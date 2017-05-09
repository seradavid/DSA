#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int v, w;
}pair;

pair a[5001];
int b[2][10001];

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int n, g;
    fscanf(fin, "%d %d", &n, &g);

    for(int i = 1; i <= n; i++)
    {
        fscanf(fin, "%d %d", &a[i].w, &a[i].v);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= g; j++)
        {
            if(a[i].w > j)
                b[1][j] = b[0][j];
            else
                b[1][j] = b[0][j] > b[0][j - a[i].w] + a[i].v ? b[0][j] : b[0][j - a[i].w] + a[i].v;
        }
        for(int j = 1; j <= g; j++)
        {
            b[0][j] = b[1][j];
        }
    }
    fprintf(fout, "%d", b[1][g]);

    fclose(fin);
    fclose(fout);
    return 0;
}
