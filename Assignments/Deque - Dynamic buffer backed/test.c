#include <stdio.h>
#include <deque.h>

int main() 
{
    Deque *dq = dequeCreate();

    dequePushFront(dq, 10);
    dequePushFront(dq, 20);
    dequePushFront(dq, 30);

    char *string = dequeToString(dq);
    printf("Deque to string: %s\n", string);

    dequePushRear(dq, 40);
    dequePushRear(dq, 50);
    dequePushRear(dq, 60);

    Deque *dq1 = dequeClone(dq);

    printf("Deque contents: ");
    while (dequeCount(dq1) > 0) {
        printf("%d ", dequePopFront(dq1));
    }
    printf("\n\n");

    dequeClear(dq);

    if(dequeIsEmpty(dq))
    {
        printf("Deque exists and is empty!\n\n");
    }

    dequePushRear(dq, 40);
    dequePushRear(dq, 50);
    dequePushRear(dq, 60);

    printf("Deque contents: ");
    while (dequeCount(dq) > 0) {
        printf("%d ", dequePopFront(dq));
    }
    printf("\n\n");

    dequePushRear(dq, 50);
    dequePushRear(dq, 60);

    printf("Front - %d\n", dequeGetFront(dq));
    printf("Rear - %d\n\n", dequeGetRear(dq));

    printf("Popping - %d\n", dequePopFront(dq));
    printf("Popping - %d\n\n", dequePopRear(dq));

    if(dequeIsEmpty(dq))
    {
        printf("Deque exists and is empty!\n\n");
    }

    dequeDone(dq);

    if(!dequeIsEmpty(dq))
    {
        printf("Deque is not empty, or doesn't exist!\n\n");
    }

    return 0;
}