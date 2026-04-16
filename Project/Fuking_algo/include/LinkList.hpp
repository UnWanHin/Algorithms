#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <limits>
//算法主要分為兩類，基於邏輯和基於數學分析出來的，想要更快的算法必須要有一定的數學推演能力

struct LinkList {
    int element{};
    LinkList *next = nullptr;
};
using Node = LinkList;

Node* InputList();

Node* MergeLinkListed(Node* LinkList1, Node* LinkList2);

Node* PartitionList(Node* head);

Node* MergekList(std::vector<Node*> &lists, int left, int right);
//定長指針
Node* RemoveNthFromEnd(Node* head, int n); //發現還是用傳參而不是完全封裝只剩LinkList的函數會對以後復用的情況友好一點

Node* MakeCircleList(Node* head, int n);

Node* InputCircleList(int n);

Node* LinkedTwoList(Node* FrontList,Node* BackList);

Node* RemoveDuplicatesElement(Node* head);

Node* RemoveElements(Node* head, int n);

Node* MergeListAtoB(Node* headA, Node* headB);

Node* GetTail(Node* head);

std::pair<int, int> TwoSumOfLinkList(std::vector<int> &numbers, int n);

//cut 'n' element to two list
std::pair<Node*, Node*> CutElement(Node* head, int n);

//基於數學邏輯的
std::pair<int, Node*> CheckWhetherIntersect(Node* headA, Node* headB);

std::pair<int, int> DetectCycle(Node* head);

//定速指針
std::pair<int, int> MiddleNode(Node* head);




void PrintList(Node* head);



//
// Created by unwan on 29/3/2026.
//

#ifndef C_PROGRAMMING_LISTLIST_HPP
#define C_PROGRAMMING_LISTLIST_HPP

#endif //C_PROGRAMMING_LISTLIST_HPP