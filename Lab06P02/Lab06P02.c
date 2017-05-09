#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

FILE *fout;

typedef struct item {
   char *data;
}Item;

Item* hashArray[SIZE];

unsigned long hash(unsigned char *data)
{
    unsigned long hash = 5381;
    int c;

    while (c = *data++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % 1000;
}

int search(char *data)
{
    int hashIndex = hash(data);

    if(hashArray[hashIndex] == NULL)
    {
        return 0;
    }

    if(hashArray[hashIndex]->data == data)
    {
        return 1;
    }

    while(hashArray[hashIndex] != NULL)
    {
        if(hashArray[hashIndex]->data == data)
        {
            return 1;
        }

        char *index = malloc(1000 * sizeof(char));
        itoa(hashIndex, index, 10);
        hashIndex = hash(index);
    }

    return 0;
}

void insert(char *data)
{
    Item *newItem = (Item*) malloc(sizeof(Item));
    newItem->data = malloc(20 * sizeof(char));
    strcpy(newItem->data, data);

    int hashIndex = hash(data);

    if(hashArray[hashIndex] == NULL)
    {
        hashArray[hashIndex] = newItem;
    }
    else
    {
        while(hashArray[hashIndex] != NULL)
        {
            char *index = malloc(1000 * sizeof(char));
            itoa(hashIndex, index, 10);
            hashIndex = hash(index);
        }

        hashArray[hashIndex] = newItem;
    }
}

void delete(char *data)
{
    int hashIndex = hash(data);
    int hash2;
    char *index = malloc(1000 * sizeof(char));
    itoa(hashIndex, index, 10);
    hash2 = hash(index);

    if(hashArray[hashIndex] == NULL)
    {
        return;
    }

    if(strcmp(hashArray[hashIndex]->data, data) == 0)
    {
        if(hashArray[hash2] == NULL)
        {
            free(hashArray[hashIndex]);
            hashArray[hashIndex] = NULL;
        }
        else
        {
            while(hashArray[hash2] != NULL)
            {
                hashArray[hashIndex] = hashArray[hash2];
                hashIndex = hash2;
                itoa(hashIndex, index, 10);
                hash2 = hash(index);
            }
        }

        return;
    }

    while(hashArray[hashIndex] != NULL)
    {
        hashIndex = hash(itoa(hashIndex));
    }

    if(hashArray[hashIndex] != NULL)
    {
        while(hashArray[hash2] != NULL)
        {
            hashArray[hashIndex] = hashArray[hash2];
            hashIndex = hash2;
            itoa(hashIndex, index, 10);
            hash2 = hash(index);
        }
    }
}

void display()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(hashArray[i] != NULL)
        {
            fprintf(fout, "%s ", hashArray[i]->data);

        }
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    char op, *letter, endline;
    letter = malloc(20 * sizeof(char));
    while(fscanf(fin, "%c%[^\n]%c", &op, letter, &endline) != EOF)
    {
        switch(op)
        {
            case 'i':
                insert(letter);
                break;
            case 'd':
                delete(letter);
                break;
            case 'f':
                search(letter);
                break;
            case 'l':
                display();
                break;
            default:
                break;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
