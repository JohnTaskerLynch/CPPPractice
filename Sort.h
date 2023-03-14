#ifndef Sort
#define Sort
#include "cstdlib"
#include "vector"
#include "iostream"
#include "Math.h";

bool checkOrder(std::vector<int> input);
std::vector<int> sortGiggle(std::vector<int> &input, long &counter);
std::vector<int> sortBogo(std::vector<int> input, long &counter);
std::vector<int> sortBogoBogo(std::vector<int> &input, long &counter);

#endif //SORT
