#include "Vector.hpp"

std::vector<int> InputInt() {
    std::vector<int> result;
    int value;
    std::cout<<"Please enter the number of elements "<<std::endl;
    while (std::cin>>value) {
        result.push_back(value);
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return result;
}

std::vector<int> PrintInt(std::vector<int> & numbers) {
    for (auto & i: numbers) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    return numbers;
}

//use left and right pointer , sorted in rules
std::pair<int, int> TwoSumOfList(std::vector<int> & numbers, int sum) {
    if (numbers.empty()) {
        return std::make_pair(-1, -1);
    }
    //sorted already ,2 pointer
    int head=0; //init
    int tail=numbers.size()-1; //init
    int count{};
    while (head != tail) {
        count = numbers.at(head)+numbers.at(tail);
        if (count==sum) {
            return std::make_pair(numbers.at(head), numbers.at(tail));
        }
        else if (count>sum) {
            tail--;
        }
        else {
            head ++;
        }
    }
    return std::make_pair(-1,-1);
}

//
// Created by unwan on 1/4/2026.
//