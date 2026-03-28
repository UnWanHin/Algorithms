#include <iostream>
#include <limits>
//Leedcode no.21
struct LinkList {
    int element{};
    LinkList *next = nullptr;
};
using Node = LinkList;

Node* InputList();
Node* MergeLinkListed(Node* LinkList1, Node* LinkList2);
void OutputLinkList(Node *head);

int main() {
    Node *Link_List_1 = InputList();
    Node *Link_List_2 = InputList();
    OutputLinkList(Link_List_1);
    OutputLinkList(Link_List_2);
    Node *Merge_Link_List = MergeLinkListed(Link_List_1,Link_List_2);
    OutputLinkList(Merge_Link_List);
    return 0;
}

#pragma region Leedcode no.21

Node* InputList() {
    Node *head = nullptr;
    Node *tail = nullptr;
    int value{};
    std::cout<<"Please input elements of Link Listed : "<<std::endl;
    while (std::cin >> value) {
        Node* newNode = new Node;
        newNode->element = value;

        if (head==nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next=nullptr;
        }
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return head;
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

    while (current_list_1 != nullptr) {
        current_head->next = current_list_1;
        current_list_1 = current_list_1->next;
    }

    while (current_list_2 != nullptr) {
        current_head->next = current_list_2;
        current_list_2 = current_list_2->next;
    }

    // Clean up remaining node;

    return head;
}

void OutputLinkList(Node *head) {
    Node *current = head;
    while (current!=nullptr) {
        std::cout<<current->element<<" ";
        current = current->next;
    }
    std::cout<<std::endl;
}

#pragma endregion
//
// Created by unwan on 28/3/2026.
//