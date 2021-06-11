/*
 * Generic linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/*
 * Initialise linked list
 */
LinkedList* createLinkedList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

/*
 * Insert data at start of linked list
 */
void insertStart(LinkedList* list, void* entry)
{
    LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    node->next = NULL;
    node->prev = NULL;
    node->data = entry;

    /* Empty list, set head to node */
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        /* New node points to the head node */
        node->next = list->head;
        /* Head node points to the new node */
        list->head = node;
        /* Set the second node prev pointer to the first node */
        node->next->prev = node;
    }
}

/*
 * Remove the first node in the linked list
 */
void* removeStart(LinkedList* list)
{
    LinkedListNode* tempNode;
    void* data;

    /* Empty list, return null */
    if (list->head == NULL)
    {
        data = NULL;
    }
    /* One node left */
    else if (list->head->next == NULL)
    {
        data = list->head->data;
        free(list->head);
        /* Set head to null, indicates list is now empty */
        list->head = NULL;
    }
    else
    {
        data = list->head->data;

        tempNode = list->head;
        /* Set head to point to the second node */
        list->head = tempNode->next;
        free(tempNode);
        /* Set first node prev to null */
        list->head->prev = NULL;
    }

    return data;
}

/*
 * Insert data at end of linked list
 */
void insertLast(LinkedList* list, void* entry)
{
    LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    node->next = NULL;
    node->prev = NULL;
    node->data = entry;

    /* Empty list, set head and tail to the node */
    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        /* Use tail pointer to insert node at the end */
        list->tail->next = node;
        /* Set the last node prev to the second last node */
        node->prev = list->tail;
        /* Set tail to last node */
        list->tail = node;
    }
}

/*
 * Remove the last node in the linked list
 */
void* removeLast(LinkedList* list)
{
    LinkedListNode* secondLastNode;
    void* data;

    /* Empty list, return null */
    if (list->head == NULL)
    {
        data = NULL;
    }
    /* One node left */
    else if (list->head->next == NULL)
    {
        data = list->head->data;
        free(list->head);

        /* Set head to null, indicates list is empty */
        list->head = NULL;
    }
    else
    {
        data = list->tail->data;

        /* Traverse back one node from tail then delete the last node */
        secondLastNode = list->tail->prev;
        /* Set tail to the second last node then free last node*/
        list->tail = secondLastNode;
        free(secondLastNode->next);
        secondLastNode->next = NULL;
    }

    return data;
}

/*
 * Free the linked list
 */
void freeLinkedList(LinkedList* list, void (*freeData)(void*))
{
    LinkedListNode *node, *nextNode;

    node = list->head;

    /* Traverse linked list */
    while (node != NULL)
    {
        /* Set nextNode to the next node before the current node is freed */
        nextNode = node->next;
        /* Use function pointer to deal with Entry struct type */
        (*freeData)(node->data);
        free(node);
        node = nextNode;
    }

    /* Free list once everything inside is freed */
    free(list);
}