/*
 * Deals with file IO, reads numbers from file
 * and store into an array
 */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

/*
 * Read from file and store elements into array
 */
void storeArray(char* filename, int* array)
{
    FILE* file = fopen(filename, "r");
    int number, size;
    int i = 0;

    /* Already checked for existing file in getFileSize */
    /* Assume always integer data type */
    /* Get first line */
    size = fscanf(file, "%d\n", &number);

    /* Go through every line in the file until no more lines */
    while (size != EOF)
    {
        /* Store number into array and increment index */
        array[i] = number;
        i++;
        /* Get next line */
        size = fscanf(file, "%d\n", &number);
    }
    
    fclose(file);
}

/*
 * Get number of lines in the file
 */
int getFileSize(char* filename)
{
    FILE* file = fopen(filename, "r");
    int count = 0;
    int size;
   
    /* File does not exist, return invalid count value
     * which terminates the program later */ 
    if (file == NULL)
    {
        count = -1;
    }
    else
    {
        /* Count number of lines in the file */
        /* Get first character of file */
        size = getc(file);
        while(size != EOF)
        {
            /* \n indicates end of one line, increment count */
            if (size == '\n')
            {
                count++;
            }

            /* Get next character */
            size = getc(file);
        }

        fclose(file);
    }
    
    return count;
}
