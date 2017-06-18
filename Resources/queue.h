#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

Node *first, *back;

void q_push(int value);
void q_pop();
int q_top();
void q_print();
void q_printf(char *filename);
