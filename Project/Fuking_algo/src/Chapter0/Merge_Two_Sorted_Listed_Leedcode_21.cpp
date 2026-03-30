#include "LinkList.hpp"
//Leedcode no.21
#pragma region Leedcode no.21
int main() {
    Node *Link_List_1 = InputList();
    Node *Link_List_2 = InputList();
    PrintList(Link_List_1);
    PrintList(Link_List_2);
    Node *Merge_Link_List = MergeLinkListed(Link_List_1,Link_List_2);
    PrintList(Merge_Link_List);
    return 0;
}
#pragma endregion
//
// Created by unwan on 28/3/2026.
//