#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "search.h"

int main()
{
    FILE *fin = fopen("data.in", "r");
    char *line = malloc(max_size * sizeof(char));
    int m;
    fgets(line, max_size, fin);
    line = line + 8;

    while(strcmp(line + 1 ,"\n") != 0)
    {
        m = atoi(line);
        n = m > n ? m : n;
        line = line + 2;
    }
    m = atoi(line);
    n = m > n ? m : n;

    fgets(line, max_size, fin);
    line = line + 8;

    while(strcmp(line + 4, "\n") != 0)
    {
        matrix[line[0] - '0'][line[2] - '0'] = 1;
        line = line + 6;
    }
    matrix[line[0] - '0'][line[2] - '0'] = 1;

    DFS(1);
    BFS(1);

    fclose(fin);
    return 0;
}
