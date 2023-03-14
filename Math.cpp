#include "Math.h"
#include "cstdlib"
#include "vector"
#include "iostream"
#include "cmath"

int factorial(int input) {
    int factorial = 1;

    for(int i = 1; i <= input; i++) {
        factorial *= i;
    }

    return factorial;
}

float randDigit() {
    double pi = std::atan(1)*4;
    std::vector<int> temp;

    for(float i = 0; i < pi; i += 0.001) {
        temp.push_back(i);
    }

    int randomIndex = rand() % temp.size();

    return temp.at(randomIndex);
}