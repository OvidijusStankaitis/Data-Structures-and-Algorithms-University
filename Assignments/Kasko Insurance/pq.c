#include "pq.h"

ADT *createADT()
{
    ADT *adt = malloc(sizeof(ADT));
    adt->count = 0;
    adt->items = malloc(MAX_SIZE * sizeof(char *));
    adt->priority = malloc(MAX_SIZE * sizeof(int));
    return adt;
}

ADT *clone(ADT *adt)
{
    ADT *new_adt = malloc(sizeof(ADT));
    new_adt->count = adt->count;
    new_adt->items = malloc(MAX_SIZE * sizeof(char *));
    for (int i = 0; i < adt->count; i++)
    {
        new_adt->items[i] = strdup(adt->items[i]);
    }
    return new_adt;
}

void makeEmpty(ADT *adt)
{
    if (!isEmpty(adt))
    {
        for (int i = 0; i < adt->count; i++)
        {
            free(adt->items[i]);
        }
        adt->count = 0;
        free(adt->priority);
    }
}

int count(ADT *adt)
{
    return adt->count;
}

int isEmpty(ADT *adt)
{
    return adt->count == 0;
}

int isFull(ADT *adt)
{
    return adt->count == MAX_SIZE;
}

char *toString(ADT *adt)
{
    const int MAX_LENGTH = 10000;
    char *str = malloc(MAX_LENGTH * sizeof(char));
    str[0] = '\0';
    strcat(str, "ADT:\n");
    if (adt->count > MAX_SIZE)
    {
        strcat(str, "There are too many items to display\n");
    }
    else
    {
        for (int i = 0; i < adt->count; i++)
        {
            strcat(str, adt->items[i]);
            strcat(str, "\n");
        }
    }
    return str;
}
// Gauna pirmo eilės elemento duomenis, neišimant jo
char *peek(ADT *adt)
{
    if (isEmpty(adt))
    {
        printf("\nPriority queue is empty!\n");
        return NULL;
    }
    return adt->items[0];
}

// Inserts a new item into the priority queue, with the given priority
void insert(ADT *adt, int client_id, int priority)
{
    if (!isFull(adt))
    {
        // Find the index where the new item should be inserted based on its priority
        int index = 0;
        for (int i = 0; i < adt->count; ++i)
        {
            if (index < adt->count && priority >= adt->priority[i])
            {
                index++;
            }
        }

        // Shift all items with higher priority to the right
        for (int i = adt->count - 1; i >= index; --i)
        {
            adt->items[i + 1] = adt->items[i];
            adt->priority[i + 1] = adt->priority[i];
        }

        // Insert the new item
        char *str = malloc(MAX_SIZE * sizeof(char));
        snprintf(str, MAX_SIZE, "%s%d", priority == 0 ? "vip" : "non-vip", client_id);
        adt->items[index] = str;
        adt->priority[index] = priority;
        adt->count++;
    }
    else
    {
        printf("ADT is full\n");
    }
}


// Removes and returns the item with the highest priority from the priority queue
char *extract(ADT *adt)
{
    if (isEmpty(adt))
    {
        printf("Priority queue is empty!\n");
        return NULL;
    }

    int max_priority = adt->priority[adt->count - 1];
    // Remove and return the item with the highest priority
    char *item = adt->items[adt->count];
    free(adt->items[adt->count]);
    adt->count--;
    return adt->items[adt->count];
}

ADT *doneADT(ADT *adt) // destroy ADT
{
    for (int i = 0; i < adt->count; i++)
    {
        free(adt->items[i]);
    }
    free(adt->priority);
    free(adt->items);
    free(adt);
    return NULL;
}
