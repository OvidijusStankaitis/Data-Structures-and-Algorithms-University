typedef struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque 
{
    struct Node *front;
    struct Node *rear;
} Deque;

Deque *createDeque();
void pushFront(struct Deque *dq, int key);
void pushRear(Deque *dq, int key);
int popFront(Deque *dq);
int popRear(Deque *dq);
int getFront(Deque *dq);
int getRear(Deque *dq);
int isEmpty(Deque *dq);
void deleteDeque(Deque *dq);