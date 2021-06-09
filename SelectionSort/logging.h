#ifndef LOGGING_H
#define LOGGING_H

#include "linkedList.h"
#include "colour.h"

typedef struct
{
    int idx;
    int swapIdx;
    int* array;
} Entry;

void addLog(int*, int, int, int, LinkedList*);
void printLogs(int*, int, LinkedList*);

#endif
