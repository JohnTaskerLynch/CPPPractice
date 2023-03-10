#include <iostream>
#include "vector"
#include "Sort.h"
#include "raylib.h"

using namespace std;

// window attributes
const int SCREEN_WIDTH = 1000, SCREEN_HEIGHT = 500, FPS_LIMIT = 60;

// input array
const vector<int> TEST_ARRAY = {1, 4, 3, 2, 6, 5, 8, 7, 9, 10, 12, 11};

// -- enter program -- //
int main(void) {
    // location of x-axis
    int xAxis = SCREEN_HEIGHT - 25;

    // pass counter
    long counter = 0;

    // initialise window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bogosort Visualization");
    SetTargetFPS(FPS_LIMIT);

    // -- main loop -- //
    while (!WindowShouldClose()) {
        // -- variable loop -- //

        // create pass array every frame
        vector<int> pass = sortBogo(TEST_ARRAY, counter);

        // TODO: fix to make offset based on no. of bars and resolution
        float offset = SCREEN_WIDTH/TEST_ARRAY.size();

        // -- end variable loop -- //

        // -- drawing -- //
        BeginDrawing();

        // x-axis line
        DrawLine(0, xAxis, SCREEN_WIDTH, xAxis, WHITE);

        // iterate through each pass value
        for(int i = 0; i < TEST_ARRAY.size(); i++) {
            // print current value to terminal
            cout << pass.at(i) << " ";

            // draw a bar relative to the height of the current value
            DrawRectangle(offset, (xAxis - (pass.at(i)*10)), 35, pass.at(i) * 10, WHITE);

            // bar x pos offset increment
            offset += 100;
        }

        // TODO: show passes counter on screen


        // newline for each pass
        cout << "- pass " << counter << endl;

        // TODO: close screen if bars get into order and display final solution
        if(checkOrder(pass)) {
            CloseWindow();
        }

        // clear current frame
        ClearBackground(BLACK);

        // -- end drawing -- //
        EndDrawing();

        // -- exit main loop -- //
    }

    // -- exit program -- //
    CloseWindow();
    return 0;
}
