#include "double_linked_list.h"

void l_push(int value)
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        fprintf(stderr, "Not enough memory");
        exit(EXIT_FAILURE);
    }

    newNode -> value = value;
    newNode -> next = newNode -> prev = NULL;

    if(first == NULL)
    {
        first = last = newNode;

        return;
    }

    newNode -> next = first;
    first -> prev = newNode;
    first = newNode;
}

void l_push_back(int value)
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        fprintf(stderr, "Not enough memory");
        exit(EXIT_FAILURE);
    }

    newNode -> value = value;
    newNode -> next = newNode -> prev = NULL;

    if(last == NULL)
    {
        first = last = newNode;

        return;
    }

    newNode -> prev = last;
    last -> next = newNode;
    last = newNode;
}

void l_push_after(int value, int after)
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        fprintf(stderr, "Not enough memory");
        exit(EXIT_FAILURE);
    }

    newNode -> value = value;
    newNode -> next = newNode -> prev = NULL;

    if(first == NULL)
    {
        first = last = newNode;

        return;
    }

    Node *p = first;
    while(p != NULL && p -> value != after)
    {
        p = p -> next;
    }

    if(p == NULL)
    {
        printf("Value not found");
        return;
    }

    if(p == last)
    {
        last -> next = newNode;
        newNode -> prev = last;
        last = newNode;
        return;
    }

    newNode -> next = p -> next;
    newNode -> prev = p;
    p -> next = newNode;
}

void l_push_before(int value, int before)
{
    Node *newNode = malloc(sizeof(Node));
    if(!newNode)
    {
        fprintf(stderr, "Not enough memory");
        exit(EXIT_FAILURE);
    }

    newNode -> value = value;
    newNode -> next = newNode -> prev = NULL;

    if(first == NULL)
    {
        first = last = newNode;

        return;
    }

    Node *p = first;
    while(p != NULL && p -> value != before)
    {
        p = p -> next;
    }

    if(p == NULL)
    {
        printf("Value not found");
        return;
    }

    if(p == first)
    {
        first -> prev = newNode;
        newNode -> next = first;
        first = newNode;
        return;
    }
    newNode -> prev = p -> prev;
    newNode -> next = p;
    p -> prev -> next = newNode;
    p -> prev = newNode;
}

void l_pop()
{
    if(first == NULL)
    {
        return;
    }

    Node *p = first;
    first -> next -> prev = NULL;
    first = first -> next;

    free(p);
    p = NULL;
}

void l_pop_back()
{
    if(last == NULL)
    {
        return;
    }

    Node *p = last;
    last -> prev -> next = NULL;
    last = last -> prev;

    free(p);
    p = NULL;
}

void l_pop_k(int k)
{
    if(first == NULL)
    {
        return;
    }

    Node *p = first;
    while(p != NULL && p -> value != k)
    {
        p = p -> next;
    }

    if(p == NULL)
    {
        printf("Value not found");
        return;
    }

    if(p == first)
    {
        l_pop();
        return;
    }
    if(p == last)
    {
        l_pop_back();
        return;
    }

    p -> next -> prev = p -> prev;
    p -> prev -> next = p -> next;

    free(p);
    p = NULL;
}

void l_pop_after(int after)
{
    if(first == NULL)
    {
        return;
    }

    Node *p = first;
    while(p != NULL && p -> value != after)
    {
        p = p -> next;
    }

    if(p == NULL || p == last)
    {
        return;
    }

    if(p -> next == last)
    {
        l_pop_back();
        return;
    }

    Node *t = p -> next;
    t -> next -> prev = p;
    p -> next = t -> next;

    free(t);
    t = NULL;
}

void l_pop_before(int before)
{
    if(first == NULL)
    {
        return;
    }

    Node *p = first;
    while(p != NULL && p -> value != before)
    {
        p = p -> next;
    }

    if(p == NULL || p == first)
    {
        return;
    }

    if(p -> prev == first)
    {
        l_pop();
        return;
    }

    Node *t = p -> prev;
    t -> prev -> next = p;
    p -> prev = t -> prev;

    free(t);
    t = NULL;
}

int l_front()
{
    if(first == NULL)
    {
        return;
    }

    return first -> value;
}

int l_back()
{
    if(last == NULL)
    {
        return;
    }

    return last -> value;
}

void l_print()
{
    for(Node *p = first; p != NULL; p = p -> next)
    {
        printf("%d ", p -> value);
    }
    printf("\n");
}

void l_print_rev()
{
    for(Node *p = last; p != NULL; p = p -> prev)
    {
        printf("%d ", p -> value);
    }
    printf("\n");
}

void l_printf(char *filename)
{
    FILE *fout = fopen(filename, "w");

    for(Node *p = first; p != NULL; p = p -> next)
    {
        fprintf(fout, "%d ", p -> value);
    }
    fprintf(fout, "\n");

    fclose(fout);
}

void l_printf_rev(char *filename)
{
    FILE *fout = fopen(filename, "w");

    for(Node *p = last; p != NULL; p = p -> prev)
    {
        fprintf(fout, "%d ", p -> value);
    }
    fprintf(fout, "\n");

    fclose(fout);
}
