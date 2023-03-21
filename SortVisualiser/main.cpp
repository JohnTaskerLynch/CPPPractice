#include <iostream>
#include "vector"
#include "Sort.h"
#include "raylib.h"
#include "cmath"
#include "Math.h"

using namespace std;

// bar dimensions
int barWidth = 12;
float offset = 0;
int barMagnitude = 20;

// input array and its complexity calculation
const vector<int> TEST_ARRAY = generateArray(barMagnitude);
int complexity = factorial(TEST_ARRAY.size());

// window attributes
const int GAP = 1;
const int SCREEN_WIDTH = (barWidth*TEST_ARRAY.size()) + ((TEST_ARRAY.size()-1)*GAP), SCREEN_HEIGHT = 600, PASSES_PER_SECOND = 110;

// temp color for counter display
CLITERAL(Color) counterColor = RED;

// -- enter program -- //
int main(void) {
    // location of x-axis
    int xAxis = SCREEN_HEIGHT - 25;

    // pass counter
    long counter = 0;

    // initialise window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SortVisualisation Visualization");
    InitAudioDevice();
    SetTargetFPS(PASSES_PER_SECOND);

    // TODO: get sound to work
    Sound beep = LoadSound("resources/roblox-death-sound_1 (1).wav");

    // -- main loop -- //
    while (!WindowShouldClose()) {
        // -- variable loop -- //
        offset = 0;

        // TODO: be able to choose a sorting algorithm


        // create pass array every frame
        vector<int> pass = sortBogo(TEST_ARRAY, counter);

        // play oof for every pass
        PlaySound(beep);

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
            offset += barWidth + GAP;
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

    // -- de-initialization --
    UnloadSound(beep);
    CloseAudioDevice();

    // -- exit program -- //
    return 0;
}
