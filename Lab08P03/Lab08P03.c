#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start, cost, speed, taken;
}worker;

int comp (const void *el1, const void *el2)
{
    worker *a = (worker *)el1;
    worker *b = (worker *)el2;

    if(a->start > b->start)
        return 1;
    else if(a->start < b->start)
        return -1;
    else
    {
        if((float)a->speed / a->cost < (float)b->speed / b->cost)
            return 1;
        else
            return -1;
    }
}

int main(int argc, char*argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int n, d;
    fscanf(fin, "%d %d", &n, &d);

    worker workers[n];

    for(int i = 0; i < n; i++)
    {
        fscanf(fin, "%d %d %d", &workers[i].start, &workers[i].cost, &workers[i].speed);
        workers[i].taken = 0;
    }

    qsort(workers, n, sizeof(worker), comp);

    int day = workers[0].start, cost = 0;
    worker w = workers[0];
    while(d > 0)
    {
        for(int i = 0; i < n ; i++)
        {
            if(workers[i].start >= day)
            {
                if(workers[i].speed >= w.speed && (float)workers[i].speed / workers[i].cost >= (float)w.speed / w.cost)
                {
                    w = workers[i];
                    if(workers[i].taken == 0)
                    {
                        cost += workers[i].cost;
                        workers[i].taken = 1;
                    }
                }
            }
        }

        day ++;
        d -= w.speed;
    }

    fprintf(fout, "%d", cost);

    fclose(fin);
    fclose(fout);
    return 0;
}
