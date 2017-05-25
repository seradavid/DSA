#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define inf 1 << 30

typedef struct
{
    int cost;
    int visited;
}pair;

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Number of arguments doesn't match");
        exit(EXIT_FAILURE);
    }

    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL)
    {
        fprintf(stderr, "Could not open input file");
        exit(EXIT_FAILURE);
    }

    FILE *fout = fopen(argv[2], "w");
    if(fout == NULL)
    {
        fprintf(stderr, "Could not open output file");
        exit(EXIT_FAILURE);
    }

    int n, m;
    fscanf(fin, "%d", &n);
    while(n != 0)
    {
        fscanf(fin, "%d", &m);

        pair g[n][n]; /// The graph
        int cost[n]; /// cost[i] - Amount of time required to get to node i

        /// Initialize the graph with 0
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                g[i][j].cost = g[i][j].visited = 0;
            }
        }

        /// Read the inputs
        for(int i = 1; i <= m; i++)
        {
            int v1, v2, t;
            fscanf(fin, "%d %d %d", &v1, &v2, &t);
            g[v1][v2].cost = g[v2][v1].cost = t;
        }

        /// Start traversing the graph in a DFS manner
        spush(1);
        cost[1] = 0;
        while(stop() != NULL)
        {
            int nod = stop();
            spop();
            int mi = inf;
            int nnod = 0;

            for(int i = 1; i <= n; i++)
            {
                if(g[nod][i].cost > 0 && g[nod][i].visited == 0 && mi > g[nod][i].cost)
                { /// If there is an edge between the nodes, and we haven't used it, and it has the minimal cost
                    mi = g[nod][i].cost; /// We update the minimal cost
                    nnod = i;            /// We take the edge
                }
            }

            if(nnod != 0) /// If we found a good node to go to
            {
                spush(nnod); /// We put it in the stack
                g[nod][nnod].visited = g[nnod][nod].visited = 1; /// We mark the edge as visited
                cost[nnod] = cost[nod] + g[nod][nnod].cost; /// And we update the cost to that edge
            }
            if(nnod == 1) /// If we reach the first node
            {
                if(cost[n] != inf) /// We check to see if we visited the last node
                {
                    printf("%d\n", cost[nod] + g[nod][1].cost); /// If we visited it, we print the cost
                    sempty(); /// And empty the stack
                }
            }
        }
        if(cost[1] == 0) /// If we didn't get back to the first node
        { /// There are no two ways to get to the last node
            printf("CAUGHT\n");
        }

        fscanf(fin, "%d", &n);
    }
    return 0;
}
