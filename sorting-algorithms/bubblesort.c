#include <stdbool.h> // for bool???? crazy
#include <stdio.h>   // for printf
#include "sorting.h"

// incremental bubble sort algorithm
// returns false if the algorithm is still running
// returns true if the array is sorted
// sortflag is true if the algorithm is still sorting (i.e. has swapped elements on this pass)
bool incrementalBubbleSort(struct sortState* state)
{
    size_t i = state->i; // for my own sanity
    size_t j = state->j; // for my own sanity

    // check if algo is done
    if(j == 1) { return true; }
    if(i >= j - 1 && !state->sortFlag) { return true; }

    // when i reaches the end of the array, reset it
    if(i >= j - 1) 
    {
        // reset i
        state->i = 0;
        i = 0;

        // lower array size by 1 to optimize sorting
        state->j--;
        j = state->j;
        if(j == 1) { return true; }

        // reset sortFlag and set color of last bar
        state->sortFlag = false;
        state->barColor[(j + 1)] = WHITE;
    }

    // pointer for my own sanity
    int* arr = state->array;

    // reset barColor
    if      (i != 0) { state->barColor[ i - 1 ] = WHITE; }
    else if (j  > 1) { state->barColor[ j - 1 ] = WHITE; }

    // set color of active bar
    state->barColor[i] = BLUE;

    // swap wrong elements
    if(arr[i] > arr[i+1])
    {
        // swap elements
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;

        // grab indexes to highlight
        state->barColor[i]   = RED;
        state->barColor[i+1] = RED;

        // set the sort flag
        state->sortFlag = true;
    }
    else
    {
        // highlight the current index
        state->barColor[i]   = GREEN;
    }

    // increment i
    state->i = i + 1;

    return false;
}