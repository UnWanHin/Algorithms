#include "LinkList.hpp"
//Leedcode no.23 用分治去處理
#pragma region Leedcode no.23
int main() {
    std::vector<Node*> lists;
    std::cout<<"Please input k :"<<std::endl;
    int k;
    std::cin>>k;
    for (int i = 0; i < k; ++i) {
        std::cout<<"Please input list "<<i+1<<":"<<std::endl;
        lists.push_back(InputList());
    }
    Node* result = MergekList(lists, 0 , k-1);
    PrintList(result);
    return 0;
}

#pragma endregion
//
// Created by unwan on 28/3/2026.
//