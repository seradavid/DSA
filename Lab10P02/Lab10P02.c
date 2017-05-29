#include <stdio.h>
#include <stdlib.h>

#define inf 1 << 31
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct
{
    int engineer, conductor;
}pair;

pair a[100];

int cost(int i , int j)
{
    if(i >= 0 && j >= 0)
    {
        if(i == 1 && j == 0)
        {
            return a[1].conductor;
        }
        else if(i - j < j)
        {
            return inf;
        }
        else
        {
            return min(cost(i - 1, j - 1) + a[i].engineer, cost(i - 1, j) + a[i].conductor);
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int n;
    fscanf(fin, "%d", &n);

    for(int i = 1; i <= n; i++)
    {
        fscanf(fin, "%d %d", &a[i].engineer, &a[i].conductor);
    }

    printf("%d", a[n].engineer + cost(n - 1, (n / 2) - 1));

    fclose(fin);
    fclose(fout);
    return 0;
}
