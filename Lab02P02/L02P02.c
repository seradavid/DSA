#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int truck_id;
    struct node *next;
}Node;

typedef struct sentry
{
    Node *front, *back;
}Sentry;

Sentry *garage; /// Store the first and last truck in the garage
Sentry *road;   /// Store the first and last truck on the road

void add_node(Sentry *s, int id)
{
    Node *newNode = malloc(sizeof(Node)); ///
    if(!newNode)                          ///
    {                                     ///
        fprintf(stderr, "Out of memory"); /// Create a new node
        exit(EXIT_FAILURE);               ///
    }                                     ///
    newNode->truck_id = id;               ///
    newNode->next = NULL;                 ///

    if(s->front == NULL && s->back == NULL) ///
    {                                       ///
        s->front = s->back = newNode;       ///
    }                                       ///
    else                                    /// Add the node to the queue
    {                                       ///
        s->back->next = newNode;            ///
        s->back = newNode;                  ///
    }                                       ///
}

void on_road(int id)
{
    add_node(road, id); /// Add truck to road
}

void enter_garage(int id)
{
    if(road->front == NULL)                          ///
    {                                                ///
        printf("There are no trucks on the road.\n"); /// Check to see if we have a truck on the road
        return;                                      ///
    }                                                ///
    if(road->front->truck_id == id) /// Check if the first truck on the road matches with the given ID
    {
        add_node(garage, id); /// Add truck to garage

        Node *t = road->front;           ///
        road->front = road->front->next; /// Remove truck from road
        free(t);                         /// Free the space
        t = NULL;                        ///
    }
    else                                                  ///
    {                                                     /// If the truck with the given ID on the road is not the first one
        printf("Truck %d can't enter the garage.\n", id); /// we can't add it to the garage
    }                                                     ///
}

void exit_garage(int id)
{
    if(garage->front == NULL)                           ///
    {                                                   ///
        printf("There are no trucks in the garage.\n"); /// Check to see if we have a truck in the garage
        return;                                         ///
    }                                                   ///
    if(garage->front->truck_id == id) /// Check to see if the first truck in the garage matches the given ID
    {
        add_node(road, id); /// Add the truck to the road

        Node *t = garage->front;             ///
        garage->front = garage->front->next; /// Remove truck from the garage
        free(t);                             /// Free the space
        t = NULL;                            ///
    }
    else                                                  ///
    {                                                     /// If the truck with the given ID is not next to the exit
        printf("Truck %d can't leave the garage.\n", id); /// we can't remove it
    }                                                     ///
}

void show_trucks(Sentry *s)
{
    if(s == garage)
    {
        printf("Garage: ");
    }
    else
    {
        printf("Road: ");
    }

    for(Node *i = s->front; i != NULL; i = i->next)
    {
        printf("%d ", i->truck_id);
    }
    printf("\n");
}

void init()
{
    road = malloc(sizeof(Sentry));
    garage = malloc(sizeof(Sentry));
    if(!road || !garage)
    {
        fprintf(stderr, "Out of memory");
        exit(EXIT_FAILURE);
    }

    road->front = road->back = NULL;
    garage->front = garage->back = NULL;
}

int main()
{
    init();

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
