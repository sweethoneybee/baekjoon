#if !defined(LINKED_LIST)
#define LINKED_LIST

#include <stdlib.h>
#include "linked_list.h"
LinkedList* makeEmpty()
{
    LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
    L->data = 0;
    L->next = NULL;
    return L;
}

int IsEmpty(LinkedList* header)
{
    return header->next == NULL;
}
int IsLast(LinkedList* header, int index)
{
    return header->next == NULL;
}
LinkedList* Find(LinkedList* list, int data)
{
    LinkedList* P; // header 처리 때문에
    P = list->next;
    while(P != NULL && P->data != data)
    {
        P = P->next;
    }
    return P;
}

// for Delete function
LinkedList* FindPrevious(LinkedList* list, int data)
{
    LinkedList* P = list->next;
    while(P->next != NULL && P->next->data != data)
    {
        P = P->next;
    }

    return P;
}
LinkedList* Insert(LinkedList* list, int index, int data)
{
    LinkedList* tmp_cell;

    tmp_cell = (LinkedList*)malloc(sizeof(LinkedList));
    
    tmp_cell->data = data;
    
}

void Delete(LinkedList* list, int index)
{
    LinkedList* P, tmp_cell;
    P = FindPrevious(list, index);
}

void DeleteList(LinkedList* head);

#endif // LINKED_LIST


