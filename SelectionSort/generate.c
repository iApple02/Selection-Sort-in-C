/*
 * Generates array of random integer values
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generate.h"

/*
 * Prompt user to enter size of the generated array
 */
int inputArraySize()
{
    int size, number;
    int exit = FALSE;
    
    do
    {
        printf("Enter the size of the array (3 to 10 inclusive): ");
        /* User input */
        size = scanf("%d", &number);

        /* Checks for integer data type
         * Remove character from input stream */
        while(getchar() != '\n');

        /* Errors from invalid input */
        if(size != 1)
        {
            printf("Only integer values are accepted.\n\n");
        }
        else if(number < 3 || number > 10)
        {
            printf("The size of the array must be between 3 to 10 inclusive.\n\n");
        }
        else
        {
            /* Valid input, exit loop */
            exit = TRUE;
        }
    /* Loop until valid input */
    } while(exit == FALSE);

    return number;
}

/*
 * Generate random values between 0 and 999 then store in the array
 */
void generate(int* array, int size)
{
    int i;    
    
    /* Random seed */
    srand(time(NULL));
    
    /* For each index in the array, store random value */
    for(i = 0; i < size; i++)
    { 
        /* Random values between 0 and 999 */  
        array[i] = (rand() % (MAXVAL - MINVAL + 1)) + MINVAL;
    }
}