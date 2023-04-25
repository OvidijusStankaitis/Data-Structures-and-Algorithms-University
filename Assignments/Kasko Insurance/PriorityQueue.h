#ifndef PRIORITYQUEUE_FUN_H
#define PRIORITYQUEUE_FUN_H

typedef struct Element
{
    int element;
    int priority;
    struct Element* next;
} Element;

Element *createNewQueue();
void DestroyQueue(Element **first);
int countElements(Element* first);
int isEmpty(Element* first);
void Insert(Element **first, int data, int priority);
void Clone(Element *first, Element **newFirst);
void makeEmpty(Element **first);
void removeElement(Element** first, int priority);
int TopElement(Element *first);
void PrintList(Element *first);
void FindElement(Element *first, int priority);

#endif // PRIORITYQUEUE_FUN_H
