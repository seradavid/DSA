#include "stack.h"

void s_push(int value)
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        fprintf(stderr, "Not enough memory");
        exit(EXIT_FAILURE);
    }

    newNode -> value = value;
    newNode -> next = NULL;

    if(top == NULL)
    {
        top = newNode;
    }
    else
    {
        newNode -> next = top;
        top = newNode;
    }
}

void s_pop()
{
    if(top == NULL)
    {
        return;
    }

    top = top -> next;
}

int s_top()
{
    if(top == NULL)
    {
        return;
    }

    return top -> value;
}

void s_print()
{
    for(Node *p = top; p != NULL; p = p -> next)
    {
        printf("%d ", p -> value);
    }
    printf("\n");
}

void s_printf(char *filename)
{
    FILE *fout = fopen(filename, "w");

    for(Node *p = top; p != NULL; p = p -> next)
    {
        fprintf(fout, "%d ", p -> value);
    }
    fprintf(fout, "\n");

    fclose(fout);
}
