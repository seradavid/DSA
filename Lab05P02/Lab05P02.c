#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    char c;
    char *name = malloc(40 * sizeof(char)), *dateOfMan = malloc(8 * sizeof(char)), *dateOfExp = malloc(8 * sizeof(char));
    char *replname = malloc(40 * sizeof(char)),  *replprice = malloc(10 * sizeof(char)), *replamount = malloc(10 * sizeof(char)), *repldateMan = malloc(8 * sizeof(char)), *repldateExp = malloc(8 * sizeof(char));
    float price;
    int amount;
    while(fscanf(fin, "%c", &c) != EOF)
    {
        switch(c)
        {
            case 'i':
                fscanf(fin, "%[^,],%f,%d,%[^,],%s", name, &price, &amount, dateOfMan, dateOfExp);
                insert(name, price, amount, dateOfMan, dateOfExp);
                break;
            case 'u':
                fscanf(fin, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]", name, replname, replprice, replamount, repldateMan, repldateExp);
                find(name, replname, replprice, replamount, repldateMan, repldateExp);
                break;
            case 'd':
                fscanf(fin, "%s", name);
                delNode(name);
                break;
            case 'c':
                fscanf(fin, "%c", &c);
                createExpired(root);
                break;
        }

        fscanf(fin, "%c", &c);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
