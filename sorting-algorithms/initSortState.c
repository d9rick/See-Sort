#include <stdlib.h>
#include <time.h>
#include "sorting.h"

// init the sortState
struct sortState initSortState(size_t size)
{
    // create unsorted array
    int* array = (int*)malloc(size * sizeof(int));
    struct Color* barColor = (Color*)malloc(size * sizeof(struct Color));

    // fill barColor with white
    for(size_t i = 0; i < size; i++)
    {
        barColor[i] = WHITE;
    }

    // randomize array
    fillArrayRandomly(array, size, 0, size);

    // init sortState
    struct sortState state = {
        array,      // array
        barColor,   // colors
        size,       // unsorted_size
        false,      // sortflag
        0,          // i
        size        // j
    };

    return state;
}

// helper function to fill the array
// written by chatGPT
// - "Write a function that fills an array with random numbers within a given range."
void fillArrayRandomly(int array[], int size, int minValue, int maxValue) {
    // Check if the range is valid
    if (minValue > maxValue || size > (maxValue - minValue + 1)) {
        return;
    }

    // Initialize the array with values within the specified range
    for (int i = 0; i < size; ++i) {
        array[i] = minValue + i;
    }

    // Shuffle the array using the Fisher-Yates algorithm
    srand(time(NULL));
    for (int i = size - 1; i > 0; --i) {
        // Generate a random index between 0 and i (inclusive)
        int randomIndex = rand() % (i + 1);

        // Swap the elements at randomIndex and i
        int temp = array[i];
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
}