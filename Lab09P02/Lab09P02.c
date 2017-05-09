#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int n;
    fscanf(fin, "%d", &n);

    double a[n];
    for(int i = 1; i <= n; i++)
    {
        fscanf(fin, "%lf", &a[i]);
    }

    int buy = 1, sell = 1, min = 1;
    double profit = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] < a[min])
        {
            min = i;
        }
        else if(a[i] - a[min] > profit)
        {
            buy = min;
            sell = i;
            profit = a[i] - a[min];
        }
    }

    fprintf(fout, "Buy on day: %d, sell on day: %d, make %f profit.", buy, sell, profit);

    fclose(fin);
    fclose(fout);
    return 0;
}
