#include "LinkList.hpp"
#pragma region Leedcode 27
int main() {
    Node* head = InputList();
    int n;
    std::cout<<"Enter the elements you want to delete from the Linked List : "<<std::endl;
    std::cin>>n;
    head = RemoveElements(head, n);
    PrintList(head);
    return 0;
}
#pragma endregion
//
// Created by unwan on 30/3/2026.
//