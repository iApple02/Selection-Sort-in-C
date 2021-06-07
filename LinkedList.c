#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

/*Initalise struct with head & tail pointer*/
LinkedList* createLinkedList()
{
    LinkedList* list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

void insertStart(LinkedList* list, void* newData)
{
    LinkedListNode* newNode;
    LinkedListNode* current;

    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    /*Assign data to struct LinkedListNode*/
    newNode->data = newData;
    
    /*If head is null, head becomes the new node, and tail becomes the head*/
    if(list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        /*list->tail = list->head;*/
        
    }
    else
    {
        current = list->head;
        newNode->next = list->head;
        current->prev = newNode;
        list->head = newNode;
    }
    list->count++;
}

void insertLast(LinkedList* list, void* newData)
{
    LinkedListNode* newNode;
    LinkedListNode* current;

    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->data = newData;
    /*If head is null, head becomes the new node, and tail becomes the head*/
    if(list->count == 0)
    {
        list->head = newNode;
        list->tail = newNode;
        /*list->tail = list->head;*/
        
    }
    else
    {
        current = list->tail;
        newNode->prev = list->tail;
        current->next = newNode;
        list->tail = newNode;
        /*newNode->prev = list->tail;*/
		/*newNode->next = NULL;*/
		/*list->tail->next = newNode;*/ /*Set next to newNode data*/
        /*list->tail = newNode;*/ /*Set tail node with newNode data*/   
    }
    list->count++;
}

void* removeStart(LinkedList* list)
{
    void* data;

    if(list->count == 0)
    {
        printf("No data in linked list to remove");
    }
    /*If head is the same data as tail, set tail and head to null*/
    /*Set both head and tail to null if only 1 data in linkedList*/
    else if(list->count == 1)
    {
        data = list->head->data;
        free(list->head);
        list->head = NULL;
        
         /*Free memory of old head*/
    }
    /*If multiple data exists, get head and next then set it to null*/
    else
    {
        data = list->head->data;
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
        
    }

    list->count--;
    /*Return address of data*/
    return data;
}

void* removeLast(LinkedList* list)
{
    void* data;

    if(list->head == NULL)
    {
        printf("No data in linked list to remove");
    }
    /*If head is the same data as tail, set tail and head to null*/
    /*Set both head and tail to null if only 1 data in linkedList*/
    else if(list->count == 1)
    {
        data = list->head->data;
        free(list->tail);
        list->tail = NULL;
    }
    /*If multiple data exists, get tail and prev then set it to null*/
    else
    {
        data = list->tail->data;
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next = NULL;
    }
    list->count--;
    return data;
}

void freeLinkedList(LinkedList* list, ListFunc funcPointer)
{
    LinkedListNode* node;

    node = list->head;
    while(node->next != NULL)
    {
        /*nextNode = node->next;
        free(node->data);
        free(node);
        node = nextNode;*/

        (*funcPointer) (node->data);
        node = node->next;
    }
    free(list);
}

void printLinkedList(LinkedList* list, ListFunc funcPointer)
{
    LinkedListNode* temp;
    while(temp->next != NULL)
    {
        (*funcPointer)(temp->data);
        temp = temp->next;
    }
    printf("\n");
}