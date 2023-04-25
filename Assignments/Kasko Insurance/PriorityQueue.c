#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"


Element *createNewQueue()
{
    Element *first;
    first = (Element*)malloc(sizeof(Element));
    first->element=0;
    first->priority=0;
    first->next=NULL;
    return first;
}
//-----------------------------------------------
void DestroyQueue(Element **first)
{
    Element *current = *first;
    Element *temp;
    while(current != temp)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    *first = NULL;
}
//------------------------------------------------
int countElements(Element* first)
{
    int num=0;
    Element* current = first;
    while(current != NULL)
    {
        num++;
        current = current->next;
    }
    return num;
}
//-------------------------------------------------
int isEmpty(Element* first)
{
    return first == NULL;
}
//-------------------------------------------------
void Insert(Element **first, int data, int priority)
{
    if(*first == NULL)
    {
        (*first) = createNewQueue();
        (*first)->element = data;
        (*first)->priority =priority;
        (*first)->next = NULL;
    }
    else
    {
        Element* temp = createNewQueue();
        temp->element = data;
        temp->priority = priority;
        temp->next =NULL;
        if((*first)->priority < priority)
        {
            temp->next = *first;
            (*first) = temp;
        }
        else
        {
            Element* current = *first;
            while(current->next != NULL && current->next->priority > priority)
                current = current->next;

            temp->next = current->next;
            current->next = temp;
        }
    }

}
//-----------------------------------------------
void Clone(Element *first, Element **newFirst)
{
    Element* current = first;
    while(current != NULL)
    {
        Insert(newFirst, current->element, current->priority);
        current = current->next;
    }
}
//----------------------------------------------------
void makeEmpty(Element **first)
{
    Element* current = *first;
    Element* next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *first = NULL;
}
//----------------------------------------------------
void removeElement(Element** first, int priority)
{
    if((*first)->priority == priority)
    {
        Element* temp = *first;
        (*first) = (*first)->next;
        free(temp);
        return;
    }


    Element* temp = *first;
    Element* current = (*first)->next;
    while(current != NULL && current->priority != priority)
    {
        temp = current;
        current = current->next;
    }
    if(current == NULL)
        return;
    temp->next = current->next;
    free(current);
}
//-----------------------------------------------------
int TopElement(Element *first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    else
        return first->element;
}
//-------------------------------------------------------
void PrintList(Element *first)
{
    if(first == NULL)
        printf("List is empty.\n");
    else
    {
        Element* temp = first;
        while(temp != NULL){
            printf("%d ; ", temp->element);
            temp = temp->next;
        }
        printf("\n\n");
    }
}
//------------------------------------------------------
void FindElement(Element *first, int priority)
{
    Element* temp = first;
    while(temp != NULL)
    {
        if(temp->priority == priority)
        {
            printf("The element you searched for is: %d\n", temp->element);
            return;
        }
        temp = temp->next;
    }
    printf("The element not found.\n");
}





