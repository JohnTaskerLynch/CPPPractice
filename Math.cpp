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
    double pi = atan(1)*4;
    std::string stringPi = std::to_string(pi);
    std::vector<int> temp;

    for(char c : stringPi) {
        if(c == '.') {
            int half = rand() % 4;
            switch(half) {
                case 1:
                    temp.push_back(8);
                    break;
                case 2:
                    temp.push_back(7);
                    break;
                case 3:
                    temp.push_back(2);
                    break;
            }
        } else {
            temp.push_back(((int)c) - 48);
        }
    }

    int randomIndex = rand() % temp.size();

    return temp.at(randomIndex);
}