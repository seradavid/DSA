#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start, finish;
}pair;

int comp (const void *el1, const void *el2)
{
    pair *a = (pair *)el1;
    pair *b = (pair *)el2;

    if(a->start > b->start)
        return 1;
    else if(a->start < b->start)
        return -1;
    else
    {
        if(a->finish > b->finish)
            return 1;
        else
            return -1;
    }
}

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int n;
    fscanf(fin, "%d", &n);

    pair x[n];

    for(int i = 0; i < n; i++)
    {
        fscanf(fin, "%d %d", &x[i].start, &x[i].finish);
    }

    qsort(x, n, sizeof(pair), comp);

    int i = 0;
    fprintf(fout, "%d ", i + 1);
    for(int j = 1; j < n; j++)
    {
        if(x[j].start >= x[i].finish)
        {
            i = j;
            fprintf(fout, "%d ", i + 1);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
