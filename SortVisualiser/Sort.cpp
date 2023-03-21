#include "Sort.h"
#include "Math.h";

bool checkOrder(std::vector<int> input) {
    bool temp = true;

    for(int i = 0; i < input.size()-1; i++) {
        if(input[i] > input[i+1]) {
            temp = false;
        }
    }

    return temp;
}

std::vector<int> sortBogo(std::vector<int> input, long &counter) {
    std::vector<int> temp;
    int tmp, randomIndex;

    for(int i : input) {
        temp.push_back(i);
    }

    for(int i = 0, n = input.size(); i < n; i++) {
        //srand(time(0));
        tmp = temp[i];
        randomIndex = rand() % input.size();
        temp[i] = temp[randomIndex];
        temp[randomIndex] = tmp;
    }

    counter++;

    return temp;
}

// TODO: fix giggle sort
std::vector<int> sortGiggle(std::vector<int> &input, long &counter) {
    std::vector<int> temp;
    int tmp, randomIndex1, randomIndex2;
    srand(time(0));

    for(int i : input) {
        temp.push_back(i);
    }

    bool go = !checkOrder(temp);

    srand(time(0));

    while(go) {
        randomIndex1 = rand() % input.size();
        randomIndex2 = rand() % input.size();
        tmp = temp[randomIndex1];
        temp[randomIndex1] = temp[randomIndex2];
        temp[randomIndex2] = tmp;

        input = temp;

        //for(int i : temp) {
        //    std::cout << i << " ";
        //}
//
        //std::cout << std::endl;

        if(checkOrder(temp)){
            break;
        }

        counter++;
    }

    return temp;
}

// TODO: fix bogobogo sort
std::vector<int> sortBogoBogo(std::vector<int> &input, long &counter) {
    std::vector<int> temp;
    int tmp, pos, randomIndex;
    srand(time(0));

    for(int i : input) {
        temp.push_back(i);
    }

    bool go = !checkOrder(temp);

    while(go) {
        for(int i = 0, n = input.size(); i < n; i++) {
            tmp = temp[i];
            randomIndex = rand() % n;
            temp[i] = temp[randomIndex];
            temp[randomIndex] = tmp;
        }

        input = temp;

        //for(int i : temp) {
        //    std::cout << i << " ";
        //}
//
        //std::cout << std::endl;

        if(checkOrder(temp)){
            break;
        }

        counter++;
    }

    return temp;
}