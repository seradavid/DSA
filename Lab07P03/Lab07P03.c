#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define max_size 100
#define inf 1<<30

typedef struct
{
    int value, cost;
}pair;

int n;
int cost[max_size];
pair matrix[max_size][max_size];

void dij()
{
    for(int i = 2; i <= n; i++)
    {
        cost[i] = inf;
    }

    qpush(1);

    while(first != NULL) /// constructie cost[]
    {
        int i = qtop();
        qpop();

        for(int j = 1; j <= n; j++) /// vecini lui i
        {
            if(matrix[i][j].value == 1) /// daca este muchie intre i si j
            {
                int c = matrix[i][j].cost; /// costul de a ajunge de la i la j
                if(cost[j] > cost[i] + c)
                {
                    cost[j] = cost[i] + c; /// update la cost la j
                    qpush(j);              /// punem pe j in coada
                }
            }
        }
    }

    /// afisare
    qpush(1);
    while(first != NULL)
    {
        int i = qtop();
        qpop();
        printf("(%d, w = %d), ", i, cost[i]);
        for(int j = 1; j <= n; j++) /// vecini lui i
        {
            if(cost[j] == cost[i] + matrix[i][j].cost && matrix[i][j].value == 1) /// verificam daca am ajuns la j prin i
            {
                qpush(j);
            }
        }
    }
    printf("\b\b ");
}

int main()
{
    FILE *fin = fopen("data.in", "r");
    int i, j, c;

    while(fscanf(fin, "%d, %d=%d", &i, &j, &c) != EOF)
    {
        n = n > i ? n : i;
        n = n > j ? n : j;
        matrix[i][j].value = 1;
        matrix[i][j].cost = c;
    }

    dij();

    fclose(fin);
    return 0;
}
