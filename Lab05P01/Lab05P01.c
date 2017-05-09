#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    char op, letter,endline;
    while(fscanf(fin, "%c%c%c", &op, &letter, &endline) != EOF)
    {
        switch(op)
        {
            case 'i':
                insert(letter);
                break;
            case 'd':
                delNode(letter);
                break;
            case 'f':
                find(letter);
                break;
            case 't':
                switch(letter)
                {
                    case 'p':
                        preorder(root);
                        break;
                    case 'i':
                        inorder(root);
                        break;
                    case 'P':
                        postorder(root);
                        break;
                }
                break;
            case 'g':
                if(letter == 'm')
                {
                    fprintf(fout, "%c\n", findMin());
                }
                else if(letter == 'M')
                {
                    fprintf(fout, "%c\n", findMax());
                }
                break;
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
