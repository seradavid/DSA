#include "stack.h"

void spush(int value)
{
    Node *newNode = malloc(sizeof(Node));
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

    top = top -> next;
}

int stop()
{
    return top -> value;
}
