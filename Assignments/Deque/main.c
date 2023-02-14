#include <deque.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Deque *deque;

    deque = createDeque();

    pushFront(deque, 10);
    pushRear(deque, 20);

    printf("%d\n", getFront(deque));
    printf("%d\n", getRear(deque));

    pushFront(deque, 30);

    int f = popFront(deque);
    int r = popRear(deque);

    printf("%d\n", f);
    printf("%d\n", r);

    printf("%d\n", getFront(deque));

    return 0;
}