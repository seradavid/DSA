#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next, *prev;
}Node;

Node *first, *last;

void l_push(int value);
void l_push_back(int value);
void l_push_after(int value, int after);
void l_push_before(int value, int before);
void l_pop();
void l_pop_back();
void l_pop_k(int k);
void l_pop_after(int after);
void l_pop_before(int before);
int l_front();
int l_back();
void l_print();
void l_print_rev();
void l_printf(char *filename);
void l_printf_rev(char *filename);

