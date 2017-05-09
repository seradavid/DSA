#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char *word;
    int nr_occ;
    struct node *next;
    struct node *prev;
}Node;

Node *first;
Node *last;

char *lower(char *word)
{
    for(int i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }

    return word;
}

Node *create_node(char *word)
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        fprintf(stderr, "Out of memory.");
        exit(EXIT_FAILURE);
    }

    newNode->word = malloc(20 * sizeof(char));
    strcpy(newNode->word, word);
    newNode->nr_occ = 1;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

Node *add_node_after(Node *n, char *word)
{
    Node *newNode = create_node(word);

    if(n == NULL)
    {
        n = newNode;
    }
    else if(n->next == NULL)
    {
        newNode->prev = n;
        last->next = newNode;
        last = newNode;
    }
    else
    {
        Node *m = n->next;
        newNode->prev = n;
        newNode->next = m;
        n->next = newNode;
        m->prev = newNode;
    }

    return n;
}


Node *add_node_before(Node *n, char *word)
{
    Node *newNode = create_node(word);

    if(n == NULL)
    {
        n = newNode;
    }
    else if(n->prev == NULL)
    {
        newNode->next = n;
        first->prev = newNode;
        first = newNode;
    }
    else
    {
        Node *p = n->prev;
        newNode->prev = p;
        newNode->next = n;
        n->prev = newNode;
        p->next = newNode;
    }

    return n;
}


void insert(char *word)
{
    if(first == NULL)
    {
        first = last = add_node_after(first, word);
    }
    else
    {
        Node *t;
        for(t = first; t->next != NULL; t = t->next)
        {
            if(strcmp(t->word, word) == 0)
            {
                t->nr_occ++;
                return;
            }
            if(strcmp(t->word, word) > 0)
            {
                t = add_node_before(t, word);
                return;
            }
        }
        if(strcmp(t->word, word) < 0)
        {
            t = add_node_after(t, word);
        }
        else
        {
            t = add_node_before(t, word);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Not enough program arguments");
        exit(EXIT_FAILURE);
    }

    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    if(fin == NULL)
    {
        fprintf(stderr, "Input file not found");
        exit(EXIT_FAILURE);
    }
    if(fout == NULL)
    {
        fprintf(stderr, "Could not open output file");
        exit(EXIT_FAILURE);
    }

    char *x = malloc(20 * sizeof(char));
    while(fscanf(fin, "%s", x) != EOF)
    {
        insert(lower(x));
    }

    for(Node *i = first; i != NULL; i = i->next)
    {
        fprintf(fout, "%s: %d\n",i->word, i->nr_occ);
    }

    printf("\n");

    for(Node *i = last; i != NULL; i = i->prev)
    {
        fprintf(fout, "%s: %d\n", i->word, i->nr_occ);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
