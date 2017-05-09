#include <stdio.h>
#include <stdlib.h>

int n;
int a[1000];

int find_top()
{
    int left = 0, right = n - 1;

    while(left <= right)
    {
        int m = (left + right) / 2;

        if(a[m] > a[m - 1] && a[m] > a[m + 1]) /// we found the top
        {
            return a[m];
        }
        else if(a[m] > a[m - 1])
        {
            left = m + 1;
        }
        else
        {
            right = m - 1;
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    fscanf(fin, "%d", &n);

    for(int i = 0; i < n; i++)
    {
        fscanf(fin, "%d", &a[i]);
    }

    fprintf(fout, "%d", find_top());

    fclose(fin);
    fclose(fout);
    return 0;
}
