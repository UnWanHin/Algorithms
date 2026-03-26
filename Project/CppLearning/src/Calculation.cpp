#include <iostream>
#include "Calculation.hpp"
int main() {
    int x{};
    int y{};
    std::cout<<"Enter x: ";
    std::cin>>x;
    std::cout<<"Enter y: ";
    std::cin>>y;
    std::cout<<"x + y = "<<add(x, y)<<std::endl;
    std::cout<<"x - y = "<<subtract(x, y)<<std::endl;
    std::cout<<"x * y = "<<multiply(x, y)<<std::endl;
    std::cout<<"x / y = "<<divide(x, y)<<std::endl;


    return 0;
}

//
// Created by unwan on 26/3/2026.
//