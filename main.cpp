#include <iostream>
#include "stdlib.h"
#include "vector"
#include "Sort.h"
#include "ctime"
#include "raylib.h"

using namespace std;

const int screenWidth = 950, screenHeight = 500;

int main(void) {
    // input array
    vector<int> testArray = {1, 4, 3, 2, 6, 5, 8, 7};

    // pass counter
    long counter;

    // initialise window
    InitWindow(screenWidth, screenHeight, "Bogo");
    SetTargetFPS(250);

    // main loop
    while (!WindowShouldClose()) {
        // variable loop
        vector<int> pass = sortBogo(testArray, counter);
        float offset = 100;

        // drawing
        BeginDrawing();
        DrawLine(0, screenHeight - 400, screenWidth, screenHeight - 400, WHITE);

        // sort
        for(int i = 0; i < testArray.size(); i++) {
            // print current value to terminal
            cout << pass.at(i);

            // draw a bar relative to the height of the current value
            DrawRectangle(offset, screenHeight - (400+pass.at(i)*10), 35, pass.at(i)*10, WHITE);

            // -- make a way to display passes here --

            // bar x pos offset increment
            offset += 100;
        }

        // newline for each pass
        cout << endl;

        // close screen if bars get into order
        if(checkOrder(pass)) {
            CloseWindow();
            return 0;
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
