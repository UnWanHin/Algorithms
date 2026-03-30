#include "LinkList.hpp"
#pragma region Leedcode no.142

int main() {
   int n{};
   std::cout<<"Please enter the position that you want to create the cycle linked list"<<std::endl;
   std::cin>>n;
   Node* head = InputCircleList(n);
   std::pair<int, int> Circleresult = DetectCycle(head);
   std::cout<<"The cycle starts at position "<<Circleresult.second<<" with value "<<Circleresult.first<<std::endl;
   return 0;
}

#pragma endregion

//
// Created by unwan on 30/3/2026.
//