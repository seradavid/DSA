#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int dp[2001][2001];

void resetdp()
{
    for(int i = 0; i <= 2000; i++)
    {
        for(int j = 0; j <= 2000; j++)
        {
            dp[i][j] = 0;
        }
    }
}

int min3(int a, int b, int c)
{
    return min(min(a, b), c);
}

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int n;
    fscanf(fin, "%d", &n);

    char *word1 = malloc(2000 * sizeof(char));
    char *word2 = malloc(2000 * sizeof(char));

    for(int k = 1; k <= n; k++)
    {
        fscanf(fin, "%s", word1);
        fscanf(fin, "%s", word2);

        resetdp();

        int len1 = strlen(word1);
        int len2 = strlen(word2);

        for(int i = 0; i <= len1; i++)
        {
            for(int j = 0; j <= len2; j++)
            {
                if(i == 0) /// If first string is empty, all we can do is copy the second one
                {
                    dp[i][j] = j;
                }
                else if(j == 0) /// If the second string is empty, all we can do is copy the first one
                {
                    dp[i][j] == i;
                }
                else if(word1[i - 1] == word2[j - 1]) /// If the last characters are the same, we ignore them and go on
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min3(dp[i][j - 1],      /// Insert
                                        dp[i - 1][j],      /// Remove
                                        dp[i - 1][j - 1]); /// Replace
                }
            }
        }

        fprintf(fout, "%d\n", dp[len1][len2]);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
