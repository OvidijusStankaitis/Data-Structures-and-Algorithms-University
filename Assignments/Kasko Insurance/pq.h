#ifndef PQ_H
#define PQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    int count;
    int *priority;
    char **items;
} ADT;

ADT *createADT();
ADT *clone(ADT *adt);
void makeEmpty(ADT *adt);
int count(ADT *adt);
int isEmpty(ADT *adt);
int isFull(ADT *adt);
char *toString(ADT *adt);
char* peek(ADT *adt);
void insert(ADT *adt, int client_id, int priority);
char *extract(ADT *adt);
ADT *doneADT(ADT *adt);
#endif