#include "search.h"

void BFS(int value)
{
    qpush(value);

    while(first != NULL)
    {
        int i = qtop();
        qpop();
        visited[i] = 1;

        printf("%d ", i);

        for(int j = 1; j <= n; j++)
        {
            if(!visited[j] && matrix[i][j] == 1)
            {
                qpush(j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
    for(int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
}

void DFS(int value)
{
    spush(value);

    while(top != NULL)
    {
        int i = stop();
        spop();
        visited[i] = 1;

        printf("%d ", i);

        for(int j = 1; j <= n; j++)
        {
            if(!visited[j] && matrix[i][j] == 1)
            {
                spush(j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
    for(int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
}
