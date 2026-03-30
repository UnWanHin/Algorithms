#pragma once
#include <iostream>
#include <vector>
#include <limits>
struct LinkList {
    int element{};
    LinkList *next = nullptr;
};
using Node = LinkList;

Node* InputList();
Node* MergeLinkListed(Node* LinkList1, Node* LinkList2);
Node* PartitionList(Node* head);
Node* MergekList(std::vector<Node*> &lists, int left, int right);
Node* RemoveNthFromEnd(Node* head, int n); //發現還是用傳參而不是完全封裝只剩LinkList的函數會對以後復用的情況友好一點
void PrintList(Node* head);



//
// Created by unwan on 29/3/2026.
//

#ifndef C_PROGRAMMING_LISTLIST_HPP
#define C_PROGRAMMING_LISTLIST_HPP

#endif //C_PROGRAMMING_LISTLIST_HPP