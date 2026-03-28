#include <iostream>
#include <limits>
#include <vector>
//Leedcode no.23 用分治去處理

struct LinkList {
    int element{};
    LinkList *next = nullptr;
};
using Node = LinkList;

Node* InputList();
Node* MergekList(std::vector<Node*> &lists, int left, int right);
Node *MergeLinkListed(Node *LinkList1, Node *LinkList2);
void PrintList(Node* head);

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

#pragma region Leedcode no.23

Node* InputList() {
    Node* head{nullptr};
    Node* tail{nullptr};
    int value{};
    while (std::cin >> value) {
        Node* newNode = new Node;
        newNode->element = value;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return head;
}

void PrintList(Node* head) {
    while (head != nullptr) {
        std::cout << head->element << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

Node* MergekList(std::vector<Node*> &lists, int left , int right) {
    if (left==right) {
        return lists[left];
    }
    int mid = (left+right)/2;
    Node* leftList = MergekList(lists, left, mid);
    Node* rightList = MergekList(lists, mid+1, right);

    return MergeLinkListed(leftList,rightList);


}

Node *MergeLinkListed(Node *LinkList1, Node *LinkList2) {
    Node* head{nullptr};
    Node* current_list_1{LinkList1};
    Node* current_list_2{LinkList2};
    Node* current_head{head};
    //preventing null pointer
    if (current_list_1 == nullptr) return current_list_2;
    if (current_list_2 == nullptr) return current_list_1;

    while (current_list_1 != nullptr && current_list_2 != nullptr ) {
        Node * newNode = new Node;
        //retake the connection;
        if (current_list_1->element <= current_list_2->element) {
            newNode->element = current_list_1->element;
            current_list_1 = current_list_1->next;
        }
        else {
            newNode->element = current_list_2->element;
            current_list_2 = current_list_2->next;
        }

        if (head==nullptr) {
            head = newNode;
            current_head = newNode;
        }
        else {
            current_head->next = newNode;
            current_head = newNode;
        }
    }

    if (current_list_1 != nullptr) {
        current_head->next = current_list_1;
        current_list_1 = current_list_1->next;
    }

    if (current_list_2 != nullptr) {
        current_head->next = current_list_2;
        current_list_2 = current_list_2->next;
    }

    // Clean up remaining node;

    return head;
}

#pragma endregion
//
// Created by unwan on 28/3/2026.
//