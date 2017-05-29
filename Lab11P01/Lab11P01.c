#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int calculateCost(int init[n][n], int fin[n][n])
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(init[i][j] != fin[i][j])
            {
                count++;
            }
        }
    }

    return count;
}

int isSafe(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void printMatrix(int m[n][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void printPath(Node *root)
{
    if(root == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->m);

    for(int i = 0; i < 15; i++)
    {
        printf("-");
    }
    printf("\n");
}

void solve(int init[n][n], int x, int y, int fin[n][n])
{
    Node *root = newNode(init, x, y, x, y, 0, NULL);
    root->cost = calculateCost(init, fin);

    pqPush(root);

    while(!pqEmpty())
    {
        Node *min = pqTop();
        pqPop();

        if(min->cost == 0)
        {
            printPath(min);
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            if(isSafe(min->x + dx[i], min->y + dy[i]))
            {
                Node *child = newNode(min->m, min->x, min->y, min->x + dx[i], min->y + dy[i], min->level + 1, min);
                child->cost = calculateCost(child->m, fin);
                pqPush(child);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int x, y;
    int init[n][n];
    int fina[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            fscanf(fin, "%d", &init[i][j]);
            fina[i][j] = i * n + j + 1;

            if(init[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
    }
    fina[n - 1][n - 1] = 0;

    solve(init, x, y, fina);

    fclose(fin);
    fclose(fout);
    return 0;
}
