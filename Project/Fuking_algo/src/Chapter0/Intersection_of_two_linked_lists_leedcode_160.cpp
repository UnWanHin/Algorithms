#include "LinkList.hpp"
#pragma region leedcode 160
int main() {
    Node *headA = InputList();
    Node *headB = InputList();
    Node *CommonList = InputList();
    headA = LinkedTwoList(headA, CommonList);
    headB = LinkedTwoList(headB, CommonList);
    std::pair<int, Node*> result = CheckWhetherIntersect(headA, headB);
    std::cout << result.first << " " << result.second << std::endl;


    return 0;
}
#pragma endregion
//
// Created by unwan on 30/3/2026.
//