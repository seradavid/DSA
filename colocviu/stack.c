#include "stack.h"

void spush(int value)
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

void spop()
{
    if(top == NULL)
    {
        return;
    }

    Node *t = top;
    top = top -> next;

    free(t);
    t= NULL;
}

int stop()
{
    if(top != NULL)
        return top -> value;
    else
        return NULL;
}

void sempty()
{
    while(top != NULL)
    {
        spop();
    }
}
