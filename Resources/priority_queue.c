#include "priority_queue.h"

void pq_push(int value, int (*cmp)(int, int))
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

    Node *p = back;
    Node *prev = NULL;
    while(p != NULL && cmp(newNode -> value, p -> value) > 0)
    {
        prev = p;
        p = p -> next;
    }

    if(p == NULL)
    {
        first -> next = newNode;
        first = newNode;

        return;
    }
    if(prev == NULL)
    {
        newNode -> next = back;
        back = newNode;

        return;
    }

    prev -> next = newNode;
    newNode -> next = p;
}

void pq_pop()
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

int pq_top()
{
    if(first == NULL)
    {
        return;
    }

    return first -> value;
}

void pq_print()
{
    for(Node *p = back; p != NULL; p = p -> next)
    {
        printf("%d ", p -> value);
    }
    printf("\n");
}

void pq_printf(char *filename)
{
    FILE *fout = fopen(filename, "w");

    for(Node *p = back; p != NULL; p = p -> next)
    {
        fprintf(fout, "%d ", p -> value);
    }
    fprintf(fout, "\n");

    fclose(fout);
}
