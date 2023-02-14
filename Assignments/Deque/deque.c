#include <deque.h>
#include <stdio.h>
#include <stdlib.h>

Node *newNode(int value)
{
    Node *temp = (Node*) malloc(sizeof(Node)); // Allocates the size of Node to temp
    temp->data = value; // The data that will be inserted into deque
    temp->next = temp->prev = NULL; // Setting next and previous to NULL because the node is not a part of the deque
    return temp; // Returns the node
}

Deque *createDeque()
{
    Deque *dq = (Deque*) malloc(sizeof(Deque)); // Allocates the size of Deque to dq
    dq->front = dq->rear = NULL; // Setting front and rear to NULL, because this func. creates an empty deque
    return dq; // Returns the empty deque
}

void pushFront(struct Deque *dq, int value) 
{
    Node *temp = newNode(value); // Creates a new node with the value that we pass to it
    if (dq->front == NULL) // Check if deck is empty
    {
        dq->front = dq->rear = temp; // If it is, front and rear are equal
        return;
    }
    dq->front->prev = temp; // Sets the prev pointer of the curr. front to temp, linking the node to the front of the deque
    temp->next = dq->front; // Sets the next pointer of the node temp to the current front, linking the node to the rest of the deque
    dq->front = temp; // Sets front to the data in the node temp
}

void pushRear(Deque *dq, int key) 
{
    Node *temp = newNode(key); // Creates a new node with the value that we pass to it
    if (dq->rear == NULL) // Check if deck is empty
    {
        dq->front = dq->rear = temp; // If it is, front and rear are equal
        return;
    }
    dq->rear->next = temp; // Sets the next pointer of the curr. rear to temp, linking the node to the rear of the deque
    temp->prev = dq->rear; // Sets the prev pointer of the node temp to the current rear, linking the node to the rest of the deque
    dq->rear = temp; // Sets rear to the data in the node temp
}

int popFront(Deque *dq) 
{
    int value = 0; // Initialising the return value
    if (dq->front == NULL) return -1; // Doesn't do anything if list is empty
    Node *temp = dq->front; // Sets temp to current front
    value = dq->front->data; // Return value is set to the data of front
    dq->front = dq->front->next; // Front is set to next, detaching the first element from the deque
    if (dq->front == NULL) dq->rear = NULL; // If front is NULL, rear is set to NULL
    else dq->front->prev = NULL; // Else, first element is set to NULL
    free(temp); // Memory of the empty first element is freed
    return value; // Returning the popped value
}

int popRear(Deque *dq) 
{
    int value = 0; // Initialising the return value
    if (dq->rear == NULL) return -1; // Doesn't do anything if list is empty
    Node *temp = dq->rear; // Sets temp to current rear
    value = dq->rear->data; // Return value is set to the data of rear
    dq->rear = dq->rear->prev; // Rear is set to prev, detaching the last element from the deque
    if (dq->rear == NULL) dq->front = NULL; // If rear is NULL, front is set to NULL
    else dq->rear->next = NULL; // Else, last element is set to NULL
    free(temp); // Memory of the empty last element is freed
    return value; // Returning the popped value
}

int getFront(Deque *dq) 
{
    if (dq->front == NULL) return -1; // If deque is empty returns error code -1
    return dq->front->data; // Else returns the data int the front
}

int getRear(Deque *dq) 
{
    if (dq->rear == NULL) return -1; // If deque is empty returns error code -1
    return dq->rear->data; // Else returns the data int the rear
}

int isEmpty(Deque *dq) 
{
    return (dq->front == NULL); // Returns 0 if true, 1 if false
}

void deleteDeque(Deque *dq)
{
    Node *temp; // Creates a temporary node
    while (dq->front != NULL) // Iterates through the deque while it is not empty
    {
        temp = dq->front; // Sets temp to front
        dq->front = dq->front->next; // Moves front node to the left
        free(temp); // Frees the node
    }
    free(dq); // Frees the empty deque
}