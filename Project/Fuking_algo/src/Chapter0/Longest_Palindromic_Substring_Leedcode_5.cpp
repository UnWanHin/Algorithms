#include "String.hpp"
#pragma region Leedcode 5

//如果不想用多函數和Class的話就要用Lambda
int main() {
    std::string s = InputString();
    s = LongestPalindromicSubstring(s);
    std::cout << s << std::endl;
    return 0;
}
#pragma endregion


//
// Created by unwan on 17/4/2026.
//