#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

Node *top;

void s_push(int value);
void s_pop();
int s_top();
void s_print();
void s_printf(char *filename);
