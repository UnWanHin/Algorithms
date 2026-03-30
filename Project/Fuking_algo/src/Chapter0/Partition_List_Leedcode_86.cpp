#include "LinkList.hpp"
//Leedcode no.86
//please remain the link is keep available
#pragma region Leedcode no.86

int main() {
    Node* LinkList = InputList();
    PrintList(LinkList);
    Node* PartitionedList = PartitionList(LinkList);
    PrintList(PartitionedList);
    return 0;
}

#pragma endregion


//
// Created by unwan on 28/3/2026.
//