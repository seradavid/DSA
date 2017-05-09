#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *xor;
}Node;

Node *first;

Node *XOR(Node *a, Node *b)
{
    return (unsigned int)a ^ (unsigned int)b;
}

void add_node(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        fprintf(stderr, "Out of memory");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->xor = XOR(first, NULL);

    if(first != NULL)
    {
        Node *next = XOR(first->xor, NULL);
        first->xor = XOR(newNode, next);
    }

    first = newNode;
}

void print(char *path)
{
    FILE *fout = fopen(path, "w");
    if(fout == NULL)
    {
        fprintf(stderr, "Could not open output file");
        exit(EXIT_FAILURE);
    }

    Node *curr = first;
    Node *prev = NULL;
    Node *next;

    while(curr != NULL)
    {
        fprintf(fout, "%d ", curr->data);
        next = XOR(prev, curr->xor);

        prev = curr;
        curr = next;
    }

    fclose(fout);
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr, "Not enough program arguments");
        exit(EXIT_FAILURE);
    }

    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL)
    {
        fprintf(stderr, "Input file not found");
        exit(EXIT_FAILURE);
    }

    first = NULL;

    int x;
    while(fscanf(fin, "%d", &x) != EOF)
    {
        add_node(x);
    }

    print(argv[2]);

    fclose(fin);

    return 0;
}
