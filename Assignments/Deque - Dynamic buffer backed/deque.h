#include <stdbool.h>

#ifndef DEQUE_H
#define DEQUE_H

typedef struct Deque Deque;

Deque *createDeque();

bool isEmpty(Deque *dq);

bool isFull(Deque *dq);

int pushFront(Deque *dq, int value);

int popFront(Deque *dq);

int pushRear(Deque *dq, int value);

int popRear(Deque *dq);

int getFront(Deque *dq);

int getRear(Deque *dq);

int getSize(Deque *dq);

int deleteDeque(Deque *dq);

void clearD(Deque *dq);

Deque *clone(Deque *dq);

#endif