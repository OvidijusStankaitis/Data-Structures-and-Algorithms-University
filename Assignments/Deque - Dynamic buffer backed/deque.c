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

Deque *createDeque() 
{
    Deque *dq = (Deque*) malloc(sizeof(Deque)); 
    dq->buffer = (int*) malloc(sizeof(int)); 
    dq->size = 0; 
    dq->deleted = false;
    return dq; 
}

bool isEmpty(Deque *dq) 
{
    if (dq->size == 0) return true;
    return false; 
}

bool isFull(Deque *dq) 
{
    int *newBuffer = (int*) malloc((dq->size + 1) * sizeof(int)); 

    if (newBuffer == NULL)
    {
        return true;
    }

    free(newBuffer); 

    return false;
}

int pushFront(Deque *dq, int value) 
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

int popFront(Deque *dq) 
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

int pushRear(Deque *dq, int value) 
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

int popRear(Deque *dq) 
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

int getFront(Deque *dq) 
{
    if (dq->size == 0 || dq->deleted) return -1; 
    return dq->buffer[0]; 
}

int getRear(Deque *dq) 
{
    if (dq->size == 0 || dq->deleted) return -1; 
    return dq->buffer[dq->size - 1]; 
}

int getSize(Deque *dq) 
{
    if (dq->deleted) return -1;
    return dq->size; 
}

int deleteDeque(Deque *dq) 
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
