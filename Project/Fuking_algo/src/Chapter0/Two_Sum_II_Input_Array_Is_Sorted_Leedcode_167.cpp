#include "Vector.hpp"
#pragma region Leedcode 167
int main() {
    std::vector<int> numbers = InputInt();
    int sum;
    std::cout<<"Before sorted :"<<std::endl;
    PrintInt(numbers);
    std::sort(numbers.begin(), numbers.end());
    std::cout<<"After sorted :"<<std::endl;
    PrintInt(numbers);
    std::cout<<"Please enter the target u want "<<std::endl;
    std::cin>>sum;
    PrintInt(numbers);
    std::pair<int, int> result = TwoSumOfList(numbers, sum);
    std::cout<<result.first<<" "<<result.second<<std::endl;
    return 0;
}

//有空自己學習下改變方向和規則

#pragma endregion

//
// Created by unwan on 31/3/2026.
//