#include <iostream>
#include "stdlib.h"
#include "vector"
#include "Sort.h"
#include "ctime"
#include "raylib.h"

using namespace std;

int screenWidth = 950, screenHeight = 500;


//vector<int> playSorter(vector<int> &testArray) {
//        long passCounter = 1;
//        int input;
//
//        cout << "This is the test array - ";
//        for(int x : testArray) {
//            cout << x << " ";
//        }
//
//        cout << "\n1: Bogosort\n2: Gigglesort\n3: Bogobogosort" << endl;
//        cout << "Pick your poison: ";
//        cin >> input;
//
//        switch(input) {
//            case 1:
//                sortBogo(testArray, passCounter);
//                cout << "Bogo sorted in " << passCounter << " passes.";
//            case 2:
//                sortGiggle(testArray, passCounter);
//                cout << "Giggle sorted in " << passCounter << " passes.";
//            case 3:
//                sortBogoBogo(testArray, passCounter);
//                cout << "Bogobogo sorted in " << passCounter << " passes.";
//            default:
//                cout << "ERR";
//        }
//}

int main(void) {
    // input array, counter for completion passes and length
    vector<int> testArray = {1, 4, 3, 6, 2, 5, 7};
    long counter;
    vector<Rectangle> bars;

    for(int i = 0; i < testArray.size(); i++) {
        bars.push_back(Rectangle());
    }

    // initialise window
    InitWindow(screenWidth, screenHeight, "Bogo");
    SetTargetFPS(1);

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
            cout << pass.at(i);
            DrawRectangle(offset, screenHeight - (400+pass.at(i)*10), 35, pass.at(i)*10, WHITE);
            //DrawText(reinterpret_cast<const char *>(counter), 250, 250, 20, WHITE);
            offset += 100;
        }

        cout << endl;

        // end drawing
        EndDrawing();
    }

    // exit program
    CloseWindow();
    return 0;
}
