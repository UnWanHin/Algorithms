#include <iostream>
#include <limits>
//Leedcode no.86
//please remain the link is keep available

struct LinkList {
    int element{};
    LinkList *next = nullptr;
};
using Node = LinkList;

Node* InputList();
void OutputList(Node* head);
Node* PartitionList(Node* head);


int main() {
    Node* LinkList = InputList();
    OutputList(LinkList);
    Node* PartitionedList = PartitionList(LinkList);
    OutputList(PartitionedList);

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

Node* PartitionList(Node* head) {
    Node* current = head;
    Node* little_current = nullptr;
    Node* large_current = nullptr;
    int Partition_elements{};
    std::cout<<"Partition Elements"<<std::endl;
    std::cin>>Partition_elements; //cin elements

    static bool IsElementExisted = 0;
    while (current!=nullptr) {
        if (current->element == Partition_elements) {
            IsElementExisted = 1;
        }
        current = current->next;
    }
    if (IsElementExisted) {
        std::cout <<"Find"<<std::endl;
    }
    else {
        std::cout<<"The elements "<<Partition_elements<<" is not exist on the List"<<std::endl;
        return head;
    }

    current = head; //reset current pointer

    Node* head_little = nullptr;
    Node* head_large = nullptr;

    while (current!=nullptr) {
        Node * newNode = new Node;
        newNode->element = current->element;
        if (current->element < Partition_elements) { //構造兩個表
            if (little_current == nullptr) { //first node
                little_current = newNode;
                head_little = little_current;
            }
            else {
                little_current->next = newNode;
                little_current = newNode;
            }
        }
        else {
            if (large_current==nullptr) {
                large_current = newNode;
                head_large = large_current;

            }
            else {
                large_current->next = newNode;
                large_current = newNode;
            }
        }
        current = current->next;
    }

    if (little_current!=nullptr) {
        little_current->next = head_large;
        head = head_little;
    }
    else {
        head = head_large;
    }
    return head;
}

void OutputList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->element << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


#pragma endregion


//
// Created by unwan on 28/3/2026.
//