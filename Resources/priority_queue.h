#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

Node *first, *back;

void pq_push(int value, int (*cmp)(int, int));
void pq_pop();
int pq_top();
void pq_print();
void pq_printf(char *filename);
