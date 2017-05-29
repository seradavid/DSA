#include "priority_queue.h"

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

Node *newNode(int m[n][n], int x, int y, int newX, int newY, int level, Node *parent)
{
    Node *nNode = malloc(sizeof(Node));

    nNode->parent = parent;
    memcpy(nNode->m, m, sizeof(nNode->m));
    swap(&nNode->m[x][y], &nNode->m[newX][newY]);
    nNode->cost = inf;
    nNode->level = level;
    nNode->x = newX;
    nNode->y = newY;

    return nNode;
}

void pqPush(Node *p)
{
    pqNode *newNode = malloc(sizeof(pqNode));
    newNode->node = p;
    newNode->next = NULL;

    if(top == NULL)
    {
        top = newNode;
        return;
    }

    pqNode *t = top;
    pqNode *prevt = NULL;
    while(t != NULL && (newNode->node->cost + newNode->node->level) > (t->node->cost + t->node->level))
    {
        prevt = t;
        t = t->next;
    }

    if(prevt != NULL)
    {
        prevt->next = newNode;
        newNode->next = t;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void pqPop()
{
    if(top == NULL)
        return;

    pqNode *tmp = top;
    top = top->next;

    free(tmp);
    tmp = NULL;
}

int pqEmpty()
{
    if(top != NULL)
        return 0;
    else
        return 1;
}

Node *pqTop()
{
    if(top != NULL)
        return top->node;
    else
        return NULL;
}
