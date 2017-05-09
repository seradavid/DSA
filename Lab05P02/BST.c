#include "BST.h"

void insert(char *name, float price, int amount, char *dateOfManufacturing, char *dateOfExpiration)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->name = malloc(40 * sizeof(char));
    newNode->dateOfManufacturing = malloc(40 * sizeof(char));
    newNode->dateOfExpiration = malloc(40 * sizeof(char));
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->amount = amount;
    strcpy(newNode->dateOfManufacturing, dateOfManufacturing);
    strcpy(newNode->dateOfExpiration, dateOfExpiration);
    newNode->left = newNode->right = NULL;

    if(root == NULL)
    {
        root = newNode;
        return;
    }
    Node *s = root;
    for( ; ; )
    {
        if(strcmp(name, s->name) < 0)
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
            if(strcmp(name, s->name) > 0)
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
                printf("Product %s already exists.\n", name);
                free(newNode);
                newNode = NULL;
                return;
            }
        }
    }
}

Node *find(char name[], char replname[], char replprice[], char replamount[], char repldateMan[], char repldateExp[])
{
    if(root == NULL)
    {
        return NULL;
    }
    Node *t = root;
    while(t != NULL)
    {
        if(strcmp(name, t->name) == 0)
        {
            if(strcmp(replname, "~") != 0)
            {
                strcpy(t->name, replname);
            }
            if(strcmp(replprice, "~") != 0)
            {
                t->price = (float)atof(replprice);
            }
            if(strcmp(replamount, "~") != 0)
            {
                t->amount = atoi(replamount);
            }
            if(strcmp(repldateMan, "~") != 0)
            {
                strcpy(t->dateOfManufacturing, repldateMan);
            }
            if(strcmp(repldateExp, "~") != 0)
            {
                strcpy(t->dateOfExpiration, repldateExp);
            }
        }
        if(strcmp(name, t->name) < 0)
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

void delNode(char name[])
{
    if(root == NULL)
    {
        fprintf(stderr, "There are no products.");
        return;
    }
    Node *t = root;
    Node *tParent;
    Node *tReplace;
    Node *tRepParent;
    int direction = 0;

    while(t != NULL && strcmp(t->name, name) != 0)
    {
        if(strcmp(name, t->name) < 0)
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
        printf("Product %s not found.\n", name);
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

void insertexp(Node *t)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->name = malloc(40 * sizeof(char));
    newNode->dateOfManufacturing = malloc(40 * sizeof(char));
    newNode->dateOfExpiration = malloc(40 * sizeof(char));
    newNode = t;

    if(rootexp == NULL)
    {
        rootexp = newNode;
        return;
    }
    Node *s = rootexp;
    for( ; ; )
    {
        if(strcmp(t->name, s->name) < 0)
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
            if(strcmp(t->name, s->name) > 0)
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
                free(newNode);
                newNode = NULL;
                return;
            }
        }
    }
}

void createExpired(Node *t)
{
    if(t == NULL)
    {
        return;
    }

    struct tm *tm;
    time_t now = time(NULL);
    char str_date[100];
    tm = localtime(&now);
    strftime(str_date, sizeof(str_date), "%y%m%d", tm);
    if(strcmp(t->dateOfExpiration, str_date) > 0)
    {
        insertexp(t);
    }
    createExpired(t->left);
    createExpired(t->right);
}
