#include <iostream>
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

inline int add(int a, int b) {
    return a + b;
}

inline int subtract(int a, int b) {
    return a - b;
}

inline int multiply(int a, int b) {
    return a * b;
}

inline int divide(int a, int b) {
    return a / b;
}


//
// Created by unwan on 26/3/2026.
//

#ifndef C_PROGRAMMING_CALCULATION_HPP
#define C_PROGRAMMING_CALCULATION_HPP

#endif //C_PROGRAMMING_CALCULATION_HPP