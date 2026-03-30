#include "LinkList.hpp"
//input link listed
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
//Merge 2 sorted linked listed
Node *MergeLinkListed(Node *LinkList1, Node *LinkList2) {
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* current_list_1{LinkList1};
    Node* current_list_2{LinkList2};

    while (current_list_1 != nullptr && current_list_2 != nullptr ) {
        Node* picked = nullptr;
        if (current_list_1->element <= current_list_2->element) {
            picked = current_list_1;
            current_list_1 = current_list_1->next;
        }
        else {
            picked = current_list_2;
            current_list_2 = current_list_2->next;
        }

        if (head == nullptr) {
            head = picked;
            tail = picked;
        }
        else {
            tail->next = picked;
            tail = picked;
        }
    }

    Node* remaining = (current_list_1 != nullptr) ? current_list_1 : current_list_2;
    if (head == nullptr) {
        return remaining;
    }
    tail->next = remaining;
    return head;
}
//output link listed
void PrintList(Node *head) {
    Node *current = head;
    while (current!=nullptr) {
        std::cout<<current->element<<" ";
        current = current->next;
    }
    std::cout<<std::endl;
}
//Merge k sorted linked listed
Node* MergekList(std::vector<Node*> &lists, int left , int right) {
    if (lists.empty() || left > right) {
        return nullptr;
    }
    if (left==right) {
        return lists[left];
    }
    int mid = (left+right)/2;
    Node* leftList = MergekList(lists, left, mid);
    Node* rightList = MergekList(lists, mid+1, right);
    return MergeLinkListed(leftList,rightList);
}
//Partition linked listed
Node* PartitionList(Node* head) {
    Node* current = head;
    int Partition_elements{};
    std::cout<<"Partition Elements"<<std::endl;
    if (!(std::cin >> Partition_elements)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return head;
    }
    Node less_dummy{};
    Node large_dummy{};
    Node* less_tail = &less_dummy;
    Node* large_tail = &large_dummy;

    while (current != nullptr) {
        Node* next_node = current->next;
        current->next = nullptr;
        if (current->element < Partition_elements) {
            less_tail->next = current;
            less_tail = current;
        }
        else {
            large_tail->next = current;
            large_tail = current;
        }
        current = next_node;
    }

    if (less_dummy.next == nullptr) {
        return large_dummy.next;
    }
    less_tail->next = large_dummy.next;
    return less_dummy.next;
}
//fast and slow pointer
Node* RemoveNthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;
    for (int i = 0; i < n+1; i++) {
        fast = fast->next;
    }
    std::cout<<"current fast pointer position : "<<fast->element<<std::endl;
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    std::cout<<"current slow pointer position : "<<slow->element<<std::endl;
    slow->next = slow->next->next;
    return head;
}

//
// Created by unwan on 29/3/2026.
//
