#include <stdio.h>
#include "sorting.h"

// helper file to give aid to the sorting functions


// literally just prints the array to the standard out
void printArray(int* array, unsigned int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        printf("%c, ", array[i] + '0');
    }
    printf("%c\n", array[size - 1] + '0');
}