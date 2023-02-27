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
    vector<int> testArray = {1, 4, 3};
    long counter;
    int n = testArray.size();

    // vector of vector for every pass computed
    vector<vector<int>> passes = sortBogo(testArray, counter);

    // drawing intial bars
    float offset = 100;
    for(int i = 0; i < n; i++) {
        vector<Rectangle> rects = {};
        offset += 100;
    }

    // initialise window
    InitWindow(screenWidth, screenHeight, "Bogo");
    SetTargetFPS(1);

    // main loop
    while (!WindowShouldClose()) {
        // variable loop


        // drawing
        BeginDrawing();
        DrawLine(0, screenHeight - 50, screenWidth, screenHeight - 50, WHITE);



        // end drawing
        EndDrawing();
    }

    // exit program
    CloseWindow();
    return 0;
}
