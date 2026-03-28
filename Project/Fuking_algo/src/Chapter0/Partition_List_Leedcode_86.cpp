#include <iostream>
#include <limits>
//Leedcode no.86

struct LinkList {
    int element{};
    LinkList *next = nullptr;
};
using Node = LinkList;

Node* InputList();
void OutputList(Node* head);
Node* PartitionList(Node* head, int x);


int main() {


    Node* LinkList = InputList();
    OutputList(LinkList);

    return 0;
}

#pragma region Leedcode no.86

Node *InputList() {
    Node *head{nullptr};
    Node *tail{nullptr};
    int value{};
    std::cout<<"Please input elements of Link Listed : "<<std::endl;
    while (std::cin >> value) {
        Node * newNode = new Node;
        newNode->element = value;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        }
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

    return head;
}

Node* PartitionList(Node* head, int x) {

}

#pragma endregion


//
// Created by unwan on 28/3/2026.
//