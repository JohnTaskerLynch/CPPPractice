#include "Sort.h"
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

int randDigit() {
    double pi = (atan(1)*4)*10000000;
    std::string stringPi = std::to_string(pi);
    std::vector<int> temp;

    for(char c : stringPi) {
        if(c == '.') {
            // nothing
        } else {
            temp.push_back(((int)c) - 48);
        }
    }

    int randomIndex = rand() % temp.size();

    return temp.at(randomIndex);
}

std::vector<int> generateArray(int length) {
    std::vector<int> temp;
    long counter = 0;

    for(int i = 1; i < length; i++) {
        temp.push_back(i);
    }

    temp = sortBogo(temp, counter);

    return temp;

}