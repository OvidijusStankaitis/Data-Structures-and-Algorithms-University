#include <stdbool.h>

#ifndef DEQUE_H
#define DEQUE_H

typedef struct Deque Deque;

Deque *dequeCreate();

bool dequeIsEmpty(Deque *dq);

bool dequeIsFull(Deque *dq);

int dequePushFront(Deque *dq, int value);

int dequePopFront(Deque *dq);

int dequePushRear(Deque *dq, int value);

int dequePopRear(Deque *dq);

int dequeGetFront(Deque *dq);

int dequeGetRear(Deque *dq);

int dequeCount(Deque *dq);

int dequeDone(Deque *dq);

void dequeClear(Deque *dq);

Deque *dequeClone(Deque *dq);

char *dequeToString(Deque *dq);

#endif