#include "BST.h"

void preorder(Node *t)
{
    if(t != NULL)
    {
        fprintf(fout, "%c ", t->key);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(Node *t)
{
    if(t != NULL)
    {
        inorder(t->left);
        fprintf(fout, "%c ", t->key);
        inorder(t->right);
    }
}

void postorder(Node *t)
{
    if(t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        fprintf(fout, "%c ", t->key);
    }
}
