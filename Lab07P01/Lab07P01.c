#include <stdio.h>
#include <stdlib.h>

#define size 100

int main()
{
    FILE *fin = fopen("data.txt", "r");
    int n;
    int matrix[size][size];
    char *line = malloc(size * sizeof(char));
    fgets(line, size, fin);

    fgets(line, size, fin);
    line = line + 8;

    while(strcmp(line + 4, "\n") != 0)
    {
        matrix[line[0] - '0'][line[2] - '0'] = 1;
        line = line + 6;
    }
    matrix[line[0] - '0'][line[2] - '0'] = 1;

    fgets(line, size, fin);
    line = line + 9;

    int el[size];

    while(strcmp(line + 1, "\n") != 0)
    {
        el[line[0] - '0'] = 1;
        line = line + 2;
    }
    el[line[0]- '0'] = 1;

    printf("V' arcs: ");

    for(int i = 0; i < size; i++)
    {
        if(el[i] == 1)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(el[j] == 1 && matrix[i][j] == 1)
                {
                    printf("(%d %d), ", i, j);
                }
            }
        }
    }

    return 0;
}
