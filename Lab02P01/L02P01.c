#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int truck_id;
    struct node *next;
}Node;

Node *garage = NULL; /// Store the last truck entered in the garage
Node *road = NULL;   /// Store the last truck entered on the road

Node *add_node(Node *n, int id)
{
    Node *newNode = malloc(sizeof(Node)); ///
    if(!newNode)                          ///
    {                                     ///
        fprintf(stderr, "Out of memory"); /// Create a new node
        exit(EXIT_FAILURE);               ///
    }                                     ///
    newNode->truck_id = id;               ///
    newNode->next = NULL;                 ///

    if(n != NULL)          ///
    {                      /// Add the node to the
        newNode->next = n; /// stack
    }                      ///
    return newNode;        ///
}

int pop_truck_from_road(int id)
{
    Node *i = road;                                   ///
    while(i->next != NULL && i->next->truck_id != id) ///
    {                                                 /// Search for the truck on the road
        i = i->next;                                  ///
    }

    if(i->next == NULL) /// If we get to the last element we check it separately
    {
        if(i->truck_id == id) /// Check if has the provided ID
        {
            Node *t = i->next; ///
            i->next = t->next; /// Remove the truck from the road
            free(t);           /// Free space
            t = NULL;          ///

            return 1;          /// Return 1 if we found it
        }
        else          ///
        {             ///
            return 0; /// If we have reached the last element and it doesn't have the right ID
        }             /// we return 0, meaning we didn't find it
    }
    else /// If we didn't get to the last element, means we found the ID
    {
        Node *t = i->next; ///
        i->next = t->next; /// Remove the truck from the road
        free(t);           /// Free space
        t = NULL;          ///

        return 1;          /// Return 1 if we found it
    }
}

void on_road(int id)
{
    road = add_node(road, id); /// Add a truck on the road
}

void enter_garage(int id)
{
    if(pop_truck_from_road(id) == 1) /// If we found the truck on the road,
    {                                /// we remove it and add it to garage
        garage = add_node(garage, id); /// Add a truck to garage
    }
    else                                             ///
    {                                                /// If the truck is not on the road
        printf("Truck %d is not on the road\n", id); /// we can't add it to the garage
    }                                                ///
}

void exit_garage(int id)
{
    if(garage == NULL)                    ///
    {                                     ///
        printf("The garage is empty.\n"); /// Check to see if we have trucks in garage
        return;                           ///
    }                                     ///
    if(garage->truck_id == id) /// Check to see if the provided ID is next to the exit
    {
        road = add_node(road, id); /// Add the truck to the road

        Node *t = garage;      ///
        garage = garage->next; /// Remove truck from garage
        free(t);               /// Free space
        t = NULL;              ///
    }
    else                                                      ///
    {                                                         /// If the truck is not next to the exit
        printf("Truck %d in not in the exit position\n", id); /// we can't remove it
    }                                                         ///
}

void show_trucks(Node *t)
{
    if(t == garage)
    {
        printf("Garage: ");
    }
    else
    {
        printf("Road: ");
    }

    for(Node *i = t; i != NULL; i = i->next)
    {
        printf("%d ", i->truck_id);
    }
    printf("\n");
}

int main()
{
    FILE *f = fopen("data.in", "r");
    if(f == NULL)
    {
        fprintf(stderr, "Failed to load file");
        exit(EXIT_FAILURE);
    }

    char *line = malloc(15 * sizeof(char)); /// Represents the command given
    char *id = malloc(5 * sizeof(char));    /// Represents the given ID
    char c;                                 /// Used for reading '\n'

    if(!line || !id)
    {
        fprintf(stderr, "Out of memory");
        exit(EXIT_FAILURE);
    }

    while(fscanf(f, "%[^(](%[^)])%c", line, id, &c) != EOF)
    {
        if(strcmp(line, "on_road") == 0)
        {
            on_road(atoi(id));
        }
        else if(strcmp(line, "enter_garage") == 0)
        {
            enter_garage(atoi(id));
        }
        else if(strcmp(line, "exit_garage") == 0)
        {
            exit_garage(atoi(id));
        }
        else if(strcmp(line, "show_trucks") == 0)
        {
            if(strcmp(id, "road") == 0)
            {
                show_trucks(road);
            }
            else
            {
                show_trucks(garage);
            }
        }
    }
    fclose(f);

    return 0;
}
