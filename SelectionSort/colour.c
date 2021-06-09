/*
 * Has functions for printing in different colours
 */

#include <stdio.h>
#include "colour.h"

/*
 * Print array numbers in red
 */
void printRedNumber(int number)
{
    /* Red */
    printf("\033[0;31m");
    /* Pad numbers with 0s to show 3 digits */
    printf("%03d ", number);
    /* Default */
    printf("\033[0m");
}

/*
 * Print array numbers in green
 */
void printGreenNumber(int number)
{
    /* Green */
    printf("\033[0;32m");
    /* Pad numbers with 0s to show 3 digits */
    printf("%03d ", number);
    /* Default */
    printf("\033[0m");
}
