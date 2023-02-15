#include <stdio.h>
#include <deque.h>

int main() {
    Deque *dq = createDeque();

    pushFront(dq, 10);
    pushFront(dq, 20);
    pushFront(dq, 30);

    pushRear(dq, 40);
    pushRear(dq, 50);
    pushRear(dq, 60);

    printf("Deque contents: ");
    while (getSize(dq) > 0) {
        printf("%d ", popFront(dq));
    }
    printf("\n\n");

    pushRear(dq, 70);
    pushRear(dq, 80);
    pushRear(dq, 90);

    printf("Deque contents: ");
    while (getSize(dq) > 0) {
        printf("%d ", popRear(dq));
    }
    printf("\n\n");

    pushFront(dq, 10);
    pushRear(dq, 70);

    printf("Front - %d\n", getFront(dq));
    printf("Rear - %d\n\n", getRear(dq));

    
    printf("Popping - %d\n", popFront(dq));
    printf("Popping - %d\n\n", popRear(dq));

    if(isEmpty(dq))
    {
        printf("Deque exists and is empty!\n\n");
    }

    deleteDeque(dq);

    if(!isEmpty(dq))
    {
        printf("Deque is not empty, or doesn't exist!\n");
    }

    return 0;
}