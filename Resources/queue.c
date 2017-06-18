#include "queue.h"

void q_push(int value)
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        fprintf(stderr, "Not enough memory");
        exit(EXIT_FAILURE);
    }

    newNode -> value = value;
    newNode -> next = NULL;

    if(first == NULL)
    {
        first = back = newNode;
        return;
    }

    newNode -> next = back;
    back = newNode;
}

void q_pop()
{
    if(first == NULL)
    {
        return;
    }

    if(first == back)
    {
        free(first);
        free(back);
        first = NULL;
        back = NULL;

        return;
    }

    Node *p = back;

    while(p -> next != first)
    {
        p = p -> next;
    }

    Node *t = first;
    first = p;
    free(t);
    t = NULL;
}

int q_top()
{
    if(first == NULL)
    {
        return;
    }

    return first->value;
}

void q_print()
{
    for(Node *p = back; p != NULL; p = p -> next)
    {
        printf("%d ", p -> value);
    }
    printf("\n");
}

void q_printf(char *filename)
{
    FILE *fout = fopen(filename, "w");

    for(Node *p = back; p != NULL; p = p -> next)
    {
        fprintf(fout, "%d ", p -> value);
    }
    fprintf(fout, "\n");

    fclose(fout);
}
