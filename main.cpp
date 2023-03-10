#include <iostream>
#include "stdlib.h"
#include "vector"
#include "Sort.h"
#include "ctime"
#include "raylib.h"

using namespace std;

const int SCREEN_WIDTH = 950, SCREEN_HEIGHT = 500;

int main(void) {
    // input array
    vector<int> testArray = {1, 4, 3, 2, 6, 5, 8, 7};

    // pass counter
    long counter;

    // initialise window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bogo");
    SetTargetFPS(250);

    // main loop
    while (!WindowShouldClose()) {
        // variable loop
        vector<int> pass = sortBogo(testArray, counter);
        float offset = 100;

        // drawing
        BeginDrawing();
        DrawLine(0, SCREEN_HEIGHT - 400, SCREEN_WIDTH, SCREEN_HEIGHT - 400, WHITE);

        // sort
        for(int i = 0; i < testArray.size(); i++) {
            // print current value to terminal
            cout << pass.at(i);

            // draw a bar relative to the height of the current value
            DrawRectangle(offset, SCREEN_HEIGHT - (400 + pass.at(i) * 10), 35, pass.at(i) * 10, WHITE);

            // TODO: show passes counter on screen

            // bar x pos offset increment
            offset += 100;
        }

        // newline for each pass
        cout << endl;

        // close screen if bars get into order
        if(checkOrder(pass)) {
            CloseWindow();
        }

        // clear current frame
        ClearBackground(BLACK);

        // end drawing
        EndDrawing();
    }

    // exit program
    CloseWindow();
    return 0;
}
