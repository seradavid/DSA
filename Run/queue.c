#include "queue.h"

void qpush(int value)
{
    Node *newNode = malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = NULL;

    if(first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        newNode -> next = last;
        last = newNode;
    }
}

void qpop()
{
    if(first == NULL || last == NULL)
    {
        return;
    }

    if(first == last)
    {
        free(first);
        free(last);
        first = NULL;
        last = NULL;

        return;
    }

    Node *p = last;

    while(p -> next != first)
    {
        p = p -> next;
    }

    Node *t = first;
    first = p;
    free(t);
    t = NULL;
}

int qtop()
{
    if(first != NULL)
        return first -> value;
    else
        return NULL;
}
