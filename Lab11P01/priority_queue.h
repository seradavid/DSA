#pragma once
#include <stdlib.h>

#define n 4
#define inf 1 << 30

typedef struct node
{
    struct node *parent;
    int m[n][n];
    int x,y;
    int cost;
    int level;
}Node;

typedef struct pq
{
    struct pq *next;
    Node *node;
}pqNode;

pqNode *top;

Node *newNode(int m[n][n], int x, int y, int newX, int newY, int level, Node *parent);
void pqPush(Node *p);
void pqPop();
int pqEmpty();
Node *pqTop();
