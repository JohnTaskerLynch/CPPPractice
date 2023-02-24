//
// Created by bongo on 23/02/2023.
//

#include "Sort.h"

static bool checkOrder(std::vector<int> input) {
    bool temp = true;
    for(int i = 0; i < input.size()-1; i++) {
        if(input[i] > input[i+1]) {
            temp = false;
        }
    }
    return temp;
}

std::vector<int> sortBogo(std::vector<int> input, int &counter) {
    std::vector<int> temp;
    int tmp, n, randomIndex;

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

        for(int i : temp) {
            std::cout << i << " ";
        }

        std::cout << std::endl;

        if(checkOrder(temp)){
            break;
        }

        counter++;
    }

    return temp;
}

std::vector<int> sortGiggle(std::vector<int> input, int &counter) {
    std::vector<int> temp;
    int tmp, randomIndex1, randomIndex2;

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

        for(int i : temp) {
            std::cout << i << " ";
        }

        std::cout << std::endl;

        if(checkOrder(temp)){
            break;
        }

        counter++;
    }

    return temp;
}