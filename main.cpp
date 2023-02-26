#include <iostream>
#include "stdlib.h"
#include "vector"
#include "Sort.h"
#include "ctime"
#include "raylib.h"

using namespace std;

int screenWidth = 1000, screenHeight = 500;


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

int main() {
    // initialise window
    InitWindow(screenWidth, screenHeight, "Bogo");

    // input array and counter for completion passes
    vector<int> testArray = {1, 4, 3, 6, 2, 5, 8, 7};
    long counter;

    // vector of vector for every pass computed
    vector<vector<int>> passes = sortBogo(testArray, counter);

    // main loop
    while (!WindowShouldClose()) {

        // every frame is here basically
        for(int i = 0; i < passes.size(); i++) {
            vector<int> tempVec = passes.at(i);

            for(n)

        }

    }

    // exit program
    CloseWindow();
    return 0;
}
