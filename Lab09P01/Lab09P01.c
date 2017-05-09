#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int n;
    fscanf(fin, "%d", &n);

    int a[n];

    for(int i = 1; i <= n; i++)
    {
        fscanf(fin, "%d", &a[i]);
    }

    int tmp_max, final_max;
    tmp_max = final_max = a[1];
    for(int i = 2; i <= n; i++)
    {
        tmp_max = a[i] > tmp_max + a[i] ? a[i] : tmp_max + a[i];
        final_max = final_max > tmp_max ? final_max : tmp_max;
    }

    fprintf(fout, "%d", final_max);

    fclose(fin);
    fclose(fout);
    return 0;
}
