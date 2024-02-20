#include "sorting.h"

#include <math.h>

void draw(struct sortState* state)
{
    // calculate bar width
    int barWidth = round((float)GetScreenWidth() / state->size);

    // draw the array
    for(unsigned int i = 0; i < state->size; i++)
    {
        int barHeight = (state->array[i] * GetScreenHeight()) / state->size;
        int xpos = round((float)i * GetScreenWidth() / state->size);
        int ypos = GetScreenHeight() - barHeight;

        // draw rect
        DrawRectangle(xpos, ypos, barWidth, barHeight, state->barColor[i]);
    }
}