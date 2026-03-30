#include "LinkList.hpp"
#pragma region Leedcode no.876

int main() {
    Node* LinkList = InputList();
    PrintList(LinkList);
    std::pair<int,int> middle_element = MiddleNode(LinkList);
    std::cout << "Middle element: " << middle_element.first <<'\n'<< "Middle distance: " << middle_element.second << std::endl;

    return 0;
}

#pragma endregion

//
// Created by unwan on 30/3/2026.
//