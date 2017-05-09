#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char name[10];
    struct node *next;
}Node;

Node *first;
Node *last;
int n;

void add_node(char name[])
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        fprintf(stderr, "Out of memory");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode->name, name);
    newNode->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = last = newNode;
    }
    else
    {
        newNode->next = first;
        last->next = newNode;
        last = newNode;
    }
}

void pop_next_node(Node *n)
{
    Node *t = n->next;
    n->next = t->next;
    free(t);
    t = NULL;
}

char *solve(Node *first)
{
    Node *t = first;
    while(t != t->next)
    {
        for(int i = 1; i < n - 1; i++, t = t->next);
        pop_next_node(t);
        t = t->next;
    }

    return t->name;
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

    fscanf(fin, "%d", &n);
    for(int i = 1; i <= n; i++)
    {
        char x[10];
        char c;
        fscanf(fin, "%s%c", x, &c);

        add_node(x);
    }

    fprintf(fout, "%s", solve(first));

    fclose(fin);
    fclose(fout);
    return 0;
}
