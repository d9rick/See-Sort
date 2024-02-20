#include "raylib.h"
#include <stdio.h>
#include <unistd.h>
#include "sorting-algorithms/sorting.h"

#define SCREENX 1200
#define SCREENY 800

int main()
{
    // init raylib
    InitWindow(SCREENX, SCREENY, "SeeSort");

    // set array size
    size_t size = 30;

    // init sortState
    struct sortState state = initSortState(size);

    // set done flag
    bool done = false;

    // setup for framerate
    double delay = 0.01f;
    double lastSortTime = GetTime();

    // game loop
    while (!WindowShouldClose() && !done)
    {
        // update
        if(GetTime() - lastSortTime > delay)
        {
            lastSortTime = GetTime();
            done = incrementalBubbleSort(&state);
        }
        else
        {
            continue;
        }

        // poll for input
        if(IsKeyPressed(KEY_ESCAPE))
        {
            break;
        }

        BeginDrawing(); // draw bubble sort

        ClearBackground(BLACK);

        draw(&state);

        EndDrawing(); // end drawing
    }

    printf("done\n");

    // close window
    CloseWindow();

    return 0;
}