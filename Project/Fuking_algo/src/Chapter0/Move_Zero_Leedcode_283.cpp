#include "LinkList.hpp"
#pragma region Leedcode 283
int main () {
    Node* head = InputList();
    std::pair<Node*,Node*> make_pair{};
    make_pair = CutElement(head, 0);
    head = MergeListAtoB(make_pair.first,make_pair.second);
    PrintList(make_pair.first);
    PrintList(make_pair.second);
    PrintList(head);
    return 0;
}

#pragma endregion

//
// Created by unwan on 31/3/2026.
//