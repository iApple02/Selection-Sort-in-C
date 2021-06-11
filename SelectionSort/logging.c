/*
 * Deals with logging components of the program
 */

#include <stdio.h>
#include <stdlib.h>
#include "logging.h"

/*
 * Add logs to the linked list, function is called after each pass in the
 * selection sort so the number of logs is equal to the length of the array
 */
void addLog(int* array, int size, int replaceIdx, int currIdx, LinkedList* logs)
{
    Entry* entry = (Entry*)malloc(sizeof(Entry));
    int* currArray = (int*)malloc(sizeof(int) * size);
    int i;

    /* Copy elements in a separate array to prevent all pointers pointing
     * to the original array */
    for(i = 0; i < size; i++)
    {
        currArray[i] = array[i];
    }
 
    /* Store data in Entry struct
     * Stores the current pass, index of smallest element and current array */
    entry->idx = currIdx;
    entry->swapIdx = replaceIdx;
    entry->array = currArray;

    /* Insert into linked list */
    insertLast(logs, entry);
}

/*
 * Print logs in the format shown in the assignment specification
 */
void printLogs(int* array, int size, LinkedList* logs)
{
    LinkedListNode* node;
    Entry* entry;
    int* currArray;
    int idx, swapIdx, i;
 
    /* Print sorted array section */
    printf("Sorted Array: ");
    for(i = 0; i < size; i++)
    {
        printGreenNumber(array[i]);
    }

    /* Print process log section */
    printf("\n\n\nProcess log:\n");    

    /* Traverse the linked list */
    node = logs->head;
    while(node != NULL)
    {
        /* Node data from each pass in selection sort */
        entry = node->data;
        idx = entry->idx;
        swapIdx = entry->swapIdx;
        currArray = entry->array;
        
        /* Print current array */
        for(i = 0; i < size; i++)
        {
            /* Highlight sorted elements */
            if(i <= idx) 
            {
                printGreenNumber(currArray[i]);
            }
            else
            {
                /* Pad with 0s to show 3 digit numbers */
                printf("%03d ", currArray[i]);
            }
        }

        /* No swaps in last iteration, print a different message */
        if(idx + 1 == size)
        {
            printf("\nThen, the last number is %03d.\n", currArray[swapIdx]);
        }
        else if(idx == swapIdx)
        {
            printf("\nValue number %d is %03d. It was already in the right spot.\n\n", idx + 1, currArray[swapIdx]);
        }
        else
        { 
            printf("\nValue number %d is %03d after replacing %03d.\n\n", idx + 1, currArray[idx], currArray[swapIdx]);
        }

        /* Get next node */
        node = node->next;
    }
}
