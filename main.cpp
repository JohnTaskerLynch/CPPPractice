#include <iostream>
#include "stdlib.h"
#include "vector"
#include "Sort.h"
#include "ctime"

using namespace std;

int main() {
    int passCounter = 1;
    int input;
    vector<int> testArray = {1, 4, 3, 6, 2, 5, 8, 7};

    cout << "This is the test array - ";
    for(int x : testArray) {
        cout << x << " ";
    }

    cout << "\n1: Bogosort\n2: Gigglesort" << endl;
    cout << "Pick your poison: ";
    cin >> input;

    switch(input) {
        case 1:
            sortBogo(testArray, passCounter);
            cout << "Bogo sorted in " << passCounter << " passes.";
        case 2:
            sortGiggle(testArray, passCounter);
            cout << "Giggle sorted in " << passCounter << " passes.";
    }
    
    return 0;
}
