/*
 * Runs main function and deals with sorting
 * and animation
 */

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "file.h"
#include "generate.h"
#include "newSleep.h"

/*
 * Takes in arguments and runs the program
 */
int main(int argc, char** argv)
{
    LinkedList* logs = createLinkedList();
    void (*freeEntryPtr)(void*) = &freeEntry;
    int* array;
    int size;

    switch(argc)
    {
        /* Generate option*/
        case 2: 
            /* Generate array */
            size = inputArraySize();
            array = (int*)malloc(sizeof(int) * size);
            generate(array, size);

            /* Sort */
            selectionSort(array, size, atof(argv[1]), logs);
            printLogs(array, size, logs);    
    
            /* Free array */
            free(array);

            break;

        /* Read from file option*/
        case 3:
            /* Get number of elements in the file */
            size = getFileSize(argv[2]);
            
            /* If the file doesn't exist, exit program */
            if (size == -1)
            {
                printf("File does not exist.\n");
            }
            else
            {
                /* Fill array */
                array = (int*)malloc(sizeof(int) * size);
                storeArray(argv[2], array);

                /* Sort */
                selectionSort(array, size, atof(argv[1]), logs);
                printLogs(array, size, logs);   
 
                /* Free array */
                free(array);
            }

            break;

        /* Invalid */
        default:
            printf("Usage: ./sort <sleepTime>. OR ./sort <sleepTime> <file>\n");
    }

    /* Free linked list */
    freeLinkedList(logs, freeEntryPtr);

    return 0;
}

/*
 * Sorts an array in ascending order, also deals with animation
 * and logs simultaneously
 */
void selectionSort(int* array, int size, float time, LinkedList* logs)
{
    int smallIdx, tempVal, i, j;
    /* Clear terminal before showing animation */
    system("clear");
 
    /* Iterate through all elements */
    for(i = 0; i < size; i++)
    {
        smallIdx = i;
        /* Compare the next elements with element i and look for the smallest
         * value */
        for(j = i + 1; j < size; j++)
        {
            /* If a smaller element is found, keep track of it */
            if(array[j] < array[smallIdx])
            {
                smallIdx = j;
            }
    
            /* Show which element is being compared indicated by ^ */
            animateArray(array, size, smallIdx, i, j, time);
        }

        /* Show swap between two positions in the array */
        animateSwap(array, size, smallIdx, i, time);
        
        /* Swap smallest value found with i */
        tempVal = array[smallIdx];
        array[smallIdx] = array[i];
        array[i] = tempVal;

        /* Log the sorting procedure for each pass (iteration) */
        addLog(array, size, smallIdx, i, logs);
    }
}

/*
 * Shows the current element being compared, the sorted elements and
 * the lowest value element as a result of the comparisons
 */
void animateArray(int* array, int size, int smallIdx, int outerIdx, int innerIdx, float time)
{
    int i;

    /* Top line is empty */
    printf("\n");

    /* Print current array */
    for(i = 0; i < size; i++)
    {
        /* Highlight lowest element in red */
        if(array[i] == array[smallIdx])
        {
            printRedNumber(array[i]);
        }
        /* Highlight sorted elements in green */
        else if(i < outerIdx)
        {
            printGreenNumber(array[i]);
        }
        else
        {
            /* Pad with 0s to make 3 digit numbers */
            printf("%03d ", array[i]);
        }
    }

    /* Bottom line */
    printf("\n");

    /* Add spacing to position the ^ character correctly
     * The spacing should start at the current element being compared, i + 1 
     * Arrow does not need to be beneath i, since the initial small index is
     * set to that and is not a comparison but an initialisation */
    for(i = 0; i < innerIdx; i++)
    {
        printf("    ");
    }

    printf(" ^\n");

    /* Sleep and clear terminal to form animation */
    newSleep(time);
    system("clear");
}

/*
 * Show the animation for the swap to position the smallest index at the front
 * of the array
 */
void animateSwap(int* array, int size, int smallIdx, int outerIdx, float time)
{
    int i, j;
    
    /* smallIdx - outerIdx gives the number of frames needed for the animation */
    for(i = 0; i < smallIdx - outerIdx; i++)
    {
        /* For the top line, add spacing until smallIdx's position */
        for(j = 0; j < outerIdx + i + 1; j++)
        {
            printf("    ");
        }
        
        printf("%d\n", array[outerIdx]);

        /* Print current array */
        for(j = 0; j < size; j++)
        {
            /* Highlight sorted elements in green */
            if(j < outerIdx)
            {
                printGreenNumber(array[j]);
            }
            /* If j matches any of the two indexes, don't show number
             * The numbers will appear on the top and bottom line instead */
            else if(j == smallIdx || j == outerIdx)
            {
                printf("    ");
            }
            else
            {
                /* Pad with 0s to make 3 digit numbers */
                printf("%03d ", array[j]);
            }
        }

        printf("\n");

        /* For the bottom line, add less spacing until outerIdx's position */
        for (j = 0; j < smallIdx - i - 1; j++)
        {
            printf("    ");
        }

        /* Print smallest element in red */
        printRedNumber(array[smallIdx]);
        printf("\n");
        
        /* Sleep and clear terminal to form animation */
        newSleep(time);
        system("clear");
    }
}

/*
 * Function to specifically free Entry struct types
 */
void freeEntry(void* data)
{
    Entry* entry = (Entry*)data;
    
    /* Free malloc'd int array */
    free(entry->array);
    free(entry);
}