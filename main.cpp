#include <iostream>
#include "stdlib.h"
#include "vector"
#include "Sort.h"
#include "ctime"
#include "raylib.h"

using namespace std;

vector<int> playSorter() {
        int passCounter = 1;
        int input;
        vector<int> testArray = {1, 4, 3, 6, 2, 5, 8, 7};

        cout << "This is the test array - ";
        for(int x : testArray) {
            cout << x << " ";
        }

        cout << "\n1: Bogosort\n2: Gigglesort\n3: Bogobogosort" << endl;
        cout << "Pick your poison: ";
        cin >> input;

        switch(input) {
            case 1:
                sortBogo(testArray, passCounter);
                cout << "Bogo sorted in " << passCounter << " passes.";
            case 2:
                sortGiggle(testArray, passCounter);
                cout << "Giggle sorted in " << passCounter << " passes.";
            case 3:
                sortBogoBogo(testArray, passCounter);
                cout << "Bogobogo sorted in " << passCounter << " passes.";
        }
}

int main() {
    playSorter();

    // main loop
    while (!WindowShouldClose()) {

    }

    return 0;
}
