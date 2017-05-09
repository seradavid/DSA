#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct node
{
    char *name;
    float price;
    int amount;
    char *dateOfManufacturing, *dateOfExpiration;
    struct node *left, *right;
}Node;

Node *root, *rootexp;
FILE *fout;

void insert(char *name, float price, int amount, char *dateOfManufacturing, char *dateOfExpiration);
void delNode(char name[]);
Node *find(char *name, char *replname, char *replprice, char *replamount, char *repldateMan, char *repldateExp);
void createExpired(Node *t);
void preorder(Node *t);
void inorder(Node *t);
void postorder(Node *t);
