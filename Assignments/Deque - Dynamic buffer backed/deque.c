#include <deque.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Deque 
{
    int *buffer; 
    int size; 
    bool deleted;
};

typedef struct Deque Deque;

Deque *dequeCreate() 
{
    Deque *dq = (Deque*) malloc(sizeof(Deque)); 
    dq->buffer = (int*) malloc(sizeof(int)); 
    dq->size = 0; 
    dq->deleted = false;
    return dq; 
}

bool dequeIsEmpty(Deque *dq) 
{
    if (dequeCount(dq) == 0) return true;
    return false; 
}

bool dequeIsFull(Deque *dq) 
{
    int *newBuffer = (int*) malloc((dq->size + 1) * sizeof(int)); 

    if (newBuffer == NULL)
    {
        return true;
    }

    free(newBuffer); 

    return false;
}

int dequePushFront(Deque *dq, int value) 
{
    if(dq->deleted) return -1;

    if (dq->size == 0)
    {
        dq->buffer[0] = value;
        dq->size++;
    }

    else
    {
        dq->size++;
        dq->buffer = realloc(dq->buffer, (dq->size) * sizeof(int));
        int n = dq->size;

        for(int i = n - 1; i > 0; i--)
        {
            dq->buffer[i] = dq->buffer[i - 1];
        }

        dq->buffer[0] = value;
    }    
    return 0;
}

int dequePopFront(Deque *dq) 
{
    if (dq->size == 0 || dq->deleted) return -1;

    int value = dq->buffer[0];
    int n = dq->size;

    for(int i = 0; i < n - 1; i++)
    {
        dq->buffer[i] = dq->buffer[i + 1];
    }

    dq->size--; 

    if (dq->size > 0)
    { 
        dq->buffer = (int*) realloc(dq->buffer, dq->size * sizeof(int));
    } 
    
    return value; 
}

int dequePushRear(Deque *dq, int value) 
{
    if(dq->deleted) return -1;

    if (dq->size == 0)
    {
        dq->buffer[0] = value;
        dq->size++;
    }

    else
    {
        dq->size++;
        dq->buffer = realloc(dq->buffer, (dq->size) * sizeof(int));
        int n = dq->size;

        dq->buffer[n - 1] = value;
    }

    return 0;
}

int dequePopRear(Deque *dq) 
{
    if (dq->size == 0 || dq->deleted) return -1; 

    int value = dq->buffer[dq->size - 1]; 
    dq->size--; 

    if (dq->size > 0) 
    {                         
        dq->buffer = (int*) realloc(dq->buffer, dq->size * sizeof(int));
    } 

    return value;                              
}

int dequeGetFront(Deque *dq) 
{
    if (dq->size == 0 || dq->deleted) return -1; 
    return dq->buffer[0]; 
}

int dequeGetRear(Deque *dq) 
{
    if (dq->size == 0 || dq->deleted) return -1; 
    return dq->buffer[dq->size - 1]; 
}

int dequeCount(Deque *dq) 
{
    if (dq->deleted) return -1;
    return dq->size; 
}

int dequeDone(Deque *dq) 
{
    if (dq->deleted) return -1;
            
    if (dq->buffer != NULL) 
    { 
        free(dq->buffer);
        dq->buffer = NULL;
    }

    dq->deleted = true;
    free(dq); 

    return 0;
}

void dequeClear(Deque *dq)
{
    dq->size = 0;
    dq->buffer = (int*) realloc(dq->buffer, dq->size + 1 * sizeof(int));
}

Deque *dequeClone(Deque *dq)
{
    Deque *dq2 = (Deque*) malloc(sizeof(Deque)); 
    dq2->buffer = (int*) malloc(dq->size * sizeof(int)); 
    dq2->buffer = dq->buffer;
    dq2->size = dq->size; 
    dq2->deleted = dq->deleted;
    return dq2; 
}

char *dequeToString(Deque *dq)
{
    char *string = (char*) malloc(dq->size * sizeof(char));

    int u = 0;
    for(int i = 0; i < dq->size; i++)
    {
        int num = dq->buffer[i];

        while (num != 0)
        {
            string[u] = num / 10 + '0'; 
            num /= 10; 
            u++;
        }
        string[u] = ' ';
        u++;
    }

    string[u - 1] = '\0';

    return string;
}
