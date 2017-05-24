#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define inf 1 << 30

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int c;
    fscanf(fin, "%d", &c);
    while(c != 0)
    {
        int n, m, v1, v2, l;
        n = c;
        fscanf(fin, "%d", &m);
        int g[n][n];
        int nr = 0;
        int cost[n];

        for(int i = 0; i <= n; i++)
        {
            cost[i] = inf;
            for(int j = 0; j <= n; j++)
            {
                g[i][j] = 0;
            }
        }

        for(int i = 1; i <= m; i++)
        {
            fscanf(fin, "%d %d %d", &v1, &v2, &l);
            g[v1][v2] = g[v2][v1] = l;
        }

        cost[1] = 0;
        qpush(1);
        while(qtop() != NULL)
        {
            int nod = qtop();
            qpop();
            for(int i = 1; i <= n; i++)
            {
                if(g[nod][i] != 0)
                {
                    if(i == 2)
                    {
                        if(cost[i] == cost[nod] + g[nod][i])
                        {
                            nr++;
                        }
                        else if(cost[i] > cost[nod] + g[nod][i])
                        {
                            nr = 1;
                            cost[i] = cost[nod] + g[nod][i];
                        }
                    }
                    else if(cost[i] >= cost[nod] + g[nod][i])
                    {
                        cost[i] = cost[nod] + g[nod][i];
                        qpush(i);
                    }
                }
            }
        }
        printf("%d\n", nr);
        fscanf(fin, "%d", &c);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
