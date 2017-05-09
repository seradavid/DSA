#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    char key;
    struct node *left, *right;
}Node;

Node *root;
FILE *fout;

void insert(char key);
void delNode(char key);
Node *find(char key);
void preorder(Node *t);
void inorder(Node *t);
void postorder(Node *t);
char findMin();
char findMax();
