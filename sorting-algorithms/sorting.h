#ifndef SORTING_H
#define SORTING_H

#include <stddef.h> // for size_t
#include "raylib.h"

// struct to hold the state of the sorting algorithm
struct sortState
{
    int* array;             // stores the actual data values, height of each bar is given by index of array
    struct Color* barColor; // stores the color of each bar
    size_t size;            // number of indices
    bool sortFlag;          // flag used by algorithms to check while they are sorting
    size_t i;               // iterator variable
    size_t j;               // iterator variable
};

// init the sortState
// params:
// - array = actual data values, height of each bar is given by index of array
// - size = number of indices
// - barColor
struct sortState initSortState(size_t size);

// draw a given array to the screen
// params:
// - array = actual data values, height of each bar is given by index of array
// - size = number of indices
// - barColor
void draw(struct sortState* state);

// prints the array that is passed to it
void printArray(int* arr, unsigned int size);

// incremental bubble sort algorithm
bool incrementalBubbleSort(struct sortState* state);

// helper function to fill the array
// written by chatGPT
void fillArrayRandomly(int array[], int size, int minValue, int maxValue);

#endif
