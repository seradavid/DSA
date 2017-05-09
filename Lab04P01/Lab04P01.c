#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct node
{
    int data;
    struct node *left, *right;
}Node;

Node *root;

void add_node(Node *t, char branch, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        if(branch == 'l')
        {
            if(t->left == NULL)
            {
                t->left = newNode;
            }
            else
            {
                fprintf(stderr, "That branch is already occupied");
            }
        }
        else if(branch == 'r')
        {
            if(t->right == NULL)
            {
                t->right = newNode;
            }
            else
            {
                fprintf(stderr, "That branch is already occupied");
            }
        }
        else
        {
            fprintf(stderr, "Please input a valid branch. (l / r)");
        }
    }
}

void preorder(Node *t)
{
    if(t != NULL)
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void inorder(Node *t)
{
    if(t != NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

void postorder(Node *t)
{
    if(t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}

Node *search_node(Node *t, int data)
{
    if(t != NULL)
    {
        if(t->data == data)
        {
            return t;
        }
        search_node(t->left, data);
        search_node(t->right, data);
    }
    else
    {
        return NULL;
    }
}

void swap(Node *t)
{
    Node *tmp = t->left;
    t->left = t->right;
    t->right = tmp;
}

int height(Node *t)
{
    if(t != NULL)
    {
        return max(height(t->left) + 1, height(t->right) + 1);
    }
    else
    {
        return 0;
    }
}

int nrLeaves(Node *t)
{
    if(t != NULL)
    {
        if(t->left == NULL && t->right == NULL)
        {
            return 1;
        }
        else
        {
            return nrLeaves(t->left) + nrLeaves(t->right);
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    FILE *f = fopen("data.in", "r");
    int node_id, data;
    char branch, x;
    while(fscanf(f, "%d %c %d%c", &node_id, &branch, &data, &x) != EOF)
    {
        if(node_id == 0)
        {
            add_node(root, branch, data);
        }
        else
        {
            Node *t = search_node(root, node_id);
            if(t != NULL)
            {
                add_node(t, branch, data);
            }
            else
            {
                fprintf(stderr, "Node can't be added");
            }
        }
    }
    inorder(root);
    printf("\n");
    swap(root);
    inorder(root);
    fclose(f);
    printf("\n");
    printf("%d", height(root));
    printf("\n");
    printf("%d", nrLeaves(root));
    return 0;
}
