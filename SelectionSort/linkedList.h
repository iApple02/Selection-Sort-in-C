#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
    struct LinkedListNode* prev;
} LinkedListNode;

typedef struct
{
    LinkedListNode* head;
    LinkedListNode* tail;
} LinkedList;

LinkedList* createLinkedList();
void insertStart(LinkedList*, void*);
void* removeStart(LinkedList*);
void insertLast(LinkedList*, void*);
void* removeLast(LinkedList*);
void freeLinkedList(LinkedList*, void (void*));

#endif