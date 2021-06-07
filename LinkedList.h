#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next; /*Used to store next address of the node*/
    struct LinkedListNode* prev; /*Used to store previous address of the node*/
} LinkedListNode;

typedef struct LinkedList
{
    LinkedListNode* head;
    LinkedListNode* tail;
    int count;
} LinkedList;

typedef void (*ListFunc)(void * data);
LinkedList* createLinkedList();
void insertStart(LinkedList* list, void* newData);
void insertLast(LinkedList* list, void* newData);
void* removeStart(LinkedList* list);
void* removeLast(LinkedList* list);
void freeLinkedList(LinkedList* list, ListFunc funcPointer);
void printLinkedList(LinkedList* list, ListFunc funcPointer);
int isEmpty(LinkedList * list);

#endif
