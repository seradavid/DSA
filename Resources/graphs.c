#include "graphs.h"

void read(char *filename)
{
    FILE *fin = fopen(filename, "r");
    if(!fin)
    {
        fprintf(stderr, "Input file not found");
        exit(EXIT_FAILURE);
    }

    fscanf(fin, "%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            fscanf(fin, "%d", &g[i][j]);
            if(!directed)
            {
                g[j][i] = g[i][j];
            }
        }
    }

    fclose(fin);
}

void read_edges(char *filename)
{
    FILE *fin = fopen(filename, "r");
    if(!fin)
    {
        fprintf(stderr, "Input file not found");
        exit(EXIT_FAILURE);
    }

    fscanf(fin, "%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y, c;
        fscanf(fin, "%d %d", &x, &y);
        if(weighted)
        {
            fscanf(fin, "%d", &c);
            g[x][y] = c;

            if(!directed)
            {
                g[y][x] = c;
            }
        }
        else
        {
            g[x][y] = 1;
            if(!directed)
            {
                g[y][x] = 1;
            }
        }
    }

    fclose(fin);
}

void bfs()
{
    for(int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    q_push(1);
    visited[1] = 1;

    while(q_top() != NULL)
    {
        int current_node = q_top();
        q_pop();
        printf("%d", current_node);

        for(int i = 1; i <= n; i++)
        {
            if(g[current_node][i] > 0 && !visited[i])
            {
                q_push(i);
            }
        }
    }
}

void dfs()
{
    for(int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    s_push(1);
    visited[1] = 1;

    while(s_top() != NULL)
    {
        int current_node = s_top();
        s_pop();
        printf("%d", current_node);

        for(int i = 1; i <= n; i++)
        {
            if(g[current_node][i] > 0 && !visited[i])
            {
                s_push(i);
            }
        }
    }
}


void dijkstra_bfs()
{
    for(int i = 1; i <= n; i++)
    {
        cost[i] = 1 << 30;
    }

    q_push(1);
    cost[1] = 0;

    while(q_top() != NULL)
    {
        int current_node = q_top();
        q_pop();

        for(int i = 1; i <= n; i++)
        {
            if(g[current_node][i] > 0)
            {
                if(cost[i] > cost[current_node] + g[current_node][i])
                {
                    cost[i] = cost[current_node] + g[current_node][i];
                    q_push(i);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        printf("%d ", cost[i]);
    }
}

void dijkstra_dfs()
{
    for(int i = 1; i <= n; i++)
    {
        cost[i] = 0;
    }

    s_push(1);
    visited[1] = 1;
    cost[1] = 0;

    while(s_top() != NULL)
    {
        int current_node = s_top();
        s_pop();

        int min = 1 << 30;
        int minn = 0;

        for(int i = 1; i <= n; i++)
        {
            if(g[current_node][i] > 0 && !visited[i])
            {
                if(g[current_node][i] < min)
                {
                    min = g[current_node][i];
                    minn = i;
                }
            }
        }

        cost[minn] = min;
        visited[minn] = 1;
        s_push(minn);
    }

    for(int i = 1; i <= n; i++)
    {
        printf("%d ", cost[i]);
    }
}
