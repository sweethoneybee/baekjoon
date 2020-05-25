// 
typedef struct 
{
    LinkedList* next;
    int data;
}LinkedList;
LinkedList* makeEmpty();
int IsEmpty(LinkedList* header);
int IsLast(LinkedList* header, int index);
LinkedList* Find(LinkedList* list, int data);
// for Delete function
LinkedList* FindPrevious(LinkedList* list, int data);
LinkedList* Insert(LinkedList* list, int index, int data);
void Delete(LinkedList* list, int index);
void DeleteList(LinkedList* head);
