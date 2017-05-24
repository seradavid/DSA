#pragma once
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

Node *first, *last;

void qpush(int value);
void qpop();
int  qtop();
