#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

FILE *fout;

typedef struct item {
   char *data;
   struct item *next;
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

    while(hashArray[hashIndex]->next != NULL)
    {
        if(hashArray[hashIndex]->data == data)
        {
            return 1;
        }

        hashArray[hashIndex] = hashArray[hashIndex]->next;
    }

    return 0;
}

void insert(char *data)
{
    Item *newItem = (Item*) malloc(sizeof(Item));
    newItem->data = malloc(20 * sizeof(char));
    strcpy(newItem->data, data);
    newItem->next = NULL;

    int hashIndex = hash(data);

    if(hashArray[hashIndex] == NULL)
    {
        hashArray[hashIndex] = newItem;
    }
    else
    {
        while(hashArray[hashIndex]->next != NULL)
        {
            hashArray[hashIndex] = hashArray[hashIndex]->next;
        }

        hashArray[hashIndex]->next = newItem;
    }
}

void delete(char *data)
{
    int hashIndex = hash(data);

    if(hashArray[hashIndex] == NULL)
    {
        return;
    }

    if(strcmp(hashArray[hashIndex]->data, data) == 0)
    {
        if(hashArray[hashIndex]->next == NULL)
        {
            free(hashArray[hashIndex]);
            hashArray[hashIndex] = NULL;
        }
        else
        {
            hashArray[hashIndex] = hashArray[hashIndex]->next;
        }

        return;
    }

    while(hashArray[hashIndex]->next != NULL)
    {
        if(hashArray[hashIndex]->data == data)
        {
            if(hashArray[hashIndex]->next == NULL)
            {
                free(hashArray[hashIndex]);
                hashArray[hashIndex] = NULL;
            }
            else
            {
                hashArray[hashIndex] = hashArray[hashIndex]->next;
            }
        }

        hashArray[hashIndex] = hashArray[hashIndex]->next;
    }
}

void display()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(hashArray[i] != NULL)
        {
            for(Item *j = hashArray[i]; j != NULL; j = j->next)
            {
                fprintf(fout, "%s ", j->data);
            }

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
