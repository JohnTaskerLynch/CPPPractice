#include <iostream>
#include "vector"
#include "Sort.h"
#include "raylib.h"
#include "cmath"

using namespace std;

// bar dimensions
int barWidth = 35;
float offset = 0;

// input array and its complexity calculation
const vector<int> TEST_ARRAY = {1, 4, 3, 2, 5, 6, 7};
int complexity = factorial(TEST_ARRAY.size());

// window attributes
const int SCREEN_WIDTH = (barWidth*TEST_ARRAY.size()), SCREEN_HEIGHT = 600, PASSES_PER_SECOND = 1000;

CLITERAL(Color) counterColor = RED;

// -- enter program -- //
int main(void) {
    // location of x-axis
    int xAxis = SCREEN_HEIGHT - 25;

    // pass counter
    long counter = 0;

    // initialise window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bogosort Visualization");
    SetTargetFPS(PASSES_PER_SECOND);

    // -- main loop -- //
    while (!WindowShouldClose()) {
        // -- variable loop -- //
        offset = 0;

        // create pass array every frame
        vector<int> pass = sortBogo(TEST_ARRAY, counter);

        // -- end variable loop -- //

        // -- drawing -- //
        BeginDrawing();

        // x-axis line
        DrawLine(0, xAxis, SCREEN_WIDTH, xAxis, BLUE);

        // iterate through each pass value
        for(int i = 0; i < TEST_ARRAY.size(); i++) {
            // print current value to terminal
            cout << pass.at(i) << " ";

            // draw a bar relative to the height of the current value
            DrawRectangle(offset, (xAxis - (pass.at(i)*10)), barWidth, pass.at(i) * 10, WHITE);

            // bar x pos offset increment
            offset += barWidth;
        }

        // show passes counter on screen
        DrawText(TextFormat("%i", counter), 1, 1, 35, counterColor);

        // display expected no. of passes to completion using expected big-o complexity
        DrawText(TextFormat("%i", complexity), 1, 36, 35, GREEN);

        // change color of counter display if it is an unlikely amount of passes
        if(counter > complexity) {
            counterColor = GREEN;
        }

        // newline for each pass
        cout << "- pass " << counter << endl;

        // TODO: close screen if bars get into order and display final solution
        if(checkOrder(pass)) {
            return 0;
        }

        // clear current frame
        ClearBackground(BLACK);

        // -- end drawing -- //
        EndDrawing();

        // -- exit main loop -- //
    }

    // -- exit program -- //
    return 0;
}
