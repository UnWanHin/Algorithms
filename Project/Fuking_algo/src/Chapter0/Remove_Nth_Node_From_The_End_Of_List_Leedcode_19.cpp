#include "LinkList.hpp"

#pragma region Leedcode no.19
int main() {
    Node* LinkList = InputList();
    int n;
    std::cout << "Enter the position from the end to remove: ";
    std::cin >> n;
    PrintList(LinkList);
    RemoveNthFromEnd(LinkList, n);
    PrintList(LinkList);
    return 0;
}
#pragma endregion

//
// Created by unwan on 30/3/2026.
//