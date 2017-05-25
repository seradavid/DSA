#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

Node *top;

void spush(int value);
void spop();
int  stop();
void sempty();
