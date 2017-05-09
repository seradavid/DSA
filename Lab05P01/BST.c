#include "BST.h"

void insert(char key)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;

    if(root == NULL)
    {
        root = newNode;
        return;
    }
    Node *s = root;
    for( ; ; )
    {
        if(key < s->key)
        {
            if(s->left == NULL)
            {
                s->left = newNode;
                return;
            }
            s = s->left;
        }
        else
        {
            if(key > s->key)
            {
                if(s->right == NULL)
                {
                    s->right = newNode;
                    return;
                }
                s = s->right;
            }
            else
            {
                printf("Key %c already exists.\n", key);
                free(newNode);
                newNode = NULL;
                return;
            }
        }
    }
}

Node *find(char key)
{
    if(root == NULL)
    {
        return NULL;
    }
    Node *t = root;
    while(t != NULL)
    {
        if(t->key == key)
        {
            return t;
        }
        if(key < t->key)
        {
            t = t->left;
        }
        else
        {
            t = t->right;
        }
    }
    return NULL;
}

void delNode(char key)
{
    if(root == NULL)
    {
        fprintf(stderr, "There are no nodes in the tree.");
        return;
    }
    Node *t = root;
    Node *tParent;
    Node *tReplace;
    Node *tRepParent;
    int direction = 0;

    while(t != NULL && t-> key != key)
    {
        if(key < t->key)
        {
            tParent = t;
            t = t->left;
            direction = -1;
        }
        else
        {
            tParent = t;
            t = t->right;
            direction = 1;
        }
    }

    if(t == NULL)
    {
        printf("Node %c not found.\n", key);
        return;
    }

    if(t->left == NULL)
    {
        tReplace = t->right;
    }
    else if(t->right == NULL)
    {
        tReplace = t->left;
    }
    else
    {
        tRepParent = t;
        tReplace = t->right;
        while(tReplace->left != NULL)
        {
            tRepParent = tReplace;
            tReplace = tReplace->left;
        }

        if(tRepParent != t)
        {
            tRepParent->left = tReplace->right;
            tReplace->right = t->right;
        }
        tReplace->left = t->left;
    }
    free(t);
    t = NULL;

    if(tParent == NULL)
    {
        root = tReplace;
    }
    else
    {
        if(direction == -1)
        {
            tParent->left = tReplace;
        }
        else
        {
            tParent->right = tReplace;
        }
    }
}

char findMin()
{
    if(root == NULL)
    {
        fprintf(stderr, "There is no tree.");
        return '\0';
    }

    Node *t = root;
    while(t->left != NULL)
    {
        t = t->left;
    }

    return t->key;
}

char findMax()
{
    if(root == NULL)
    {
        fprintf(stderr, "There is no tree.");
        return '\0';
    }
    Node *t = root;
    while(t->right != NULL)
    {
        t = t->right;
    }

    return t->key;
}
