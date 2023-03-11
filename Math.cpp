#include "Math.h"

int factorial(int input) {
    int factorial = 1;

    for(int i = 1; i <= input; i++) {
        factorial *= i;
    }

    return factorial;
}