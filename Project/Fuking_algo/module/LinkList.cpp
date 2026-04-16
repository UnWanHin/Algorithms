#include "LinkList.hpp"
//output link listed
void PrintList(Node *head) {
    Node *current = head;
    while (current!=nullptr) {
        std::cout<<current->element<<" ";
        current = current->next;
    }
    std::cout<<std::endl;
}
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
//fast and slow pointer for const distance
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

Node* MakeCircleList(Node* head, int n) {
    if (head == nullptr) return head;
    Node* current = head;
    Node* tail = head;
    int distance{1};
    while (tail->next != nullptr) {
        tail = tail->next;
        distance++;
    }
    if (distance < n ) {
        std::cout<<"Distance is less than n, please run again"<<std::endl;
        return head;
    }
    for ( int i = 0 ; i < n-1 ; i++) {
        current = current->next;
    }
    tail->next = current;

    return head;
}

Node* InputCircleList(int n) {
    Node* head = InputList();
    head = MakeCircleList(head, n);
    return head;
}

Node* LinkedTwoList(Node* FrontList,Node* BackList){
    Node* current = FrontList;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = BackList;
    return FrontList;
}

Node* RemoveDuplicatesElement(Node *head) {
    Node* current = head;
    int count{1};
    while (current != nullptr && current->next != nullptr) {
        if (current->element == current->next->element) {
            current->next = current->next->next;
        } else {
            current = current->next;
            count++;
        }
    }
    std::cout<<"count: "<<count<<std::endl;
    return head;
}
//Please do the afterline work every project
Node* RemoveElements(Node *head, int n) {
    Node* current = head;
    while (current != nullptr) {
        while (current->next->element == n) {
            if (current->next->next==nullptr) {
                current->next = nullptr;
                break;
            }
            current->next = current->next->next;
        }
        current = current ->next;
    }
    return head;
}
//Only Merge, No Sorted
Node* MergeListAtoB(Node* headA,Node* headB) {
    if (headA == nullptr || headB == nullptr) {
        return headA == nullptr ? headB : headA;
    }
    Node* current = headA;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = headB;
    return headA    ;
}

Node *GetTail(Node *head) {
    Node* tail = head;
    while (tail->next!=nullptr) {
        tail = tail->next;
    }
    return tail;
}

std::pair<Node*,Node*> CutElement(Node *head, int n) {
    Node keepDummy{};
    Node cutDummy{};
    Node* keepTail = &keepDummy;
    Node* cutTail = &cutDummy;

    Node* cur = head;
    while (cur != nullptr) {
        Node* next = cur->next;
        cur->next = nullptr; // 先斷開，避免舊鏈影響

        if (cur->element == n) {
            cutTail->next = cur;
            cutTail = cur;
        } else {
            keepTail->next = cur;
            keepTail = cur;
        }
        cur = next;
    }

    return {keepDummy.next, cutDummy.next};
}

std::pair<int, int> DetectCycle(Node *head) {
    if (head == nullptr) return std::make_pair(0, 0);
    std::pair<int, int> DetectCycle{};
    Node* fast = head;
    Node* slow = head;
    int counter{1};
    do {
        fast = fast->next->next;
        slow = slow->next;
    }
    while (fast != slow);

    std::cout<<"current fast pointer position : "<<fast->element<<std::endl;
    std::cout<<"current slow pointer position : "<<slow->element<<std::endl;
    Node* start = head;
    while (start != slow) {
        start = start->next;
        slow = slow->next;
        counter++;
    }
    DetectCycle.first = start->element;
    DetectCycle.second = counter;

    return DetectCycle;
}

std::pair<int, Node*> CheckWhetherIntersect(Node* headA, Node* headB) {
    if (headA == nullptr || headB == nullptr) return std::make_pair(0, nullptr);
    Node* LinkListA = headA;
    Node* LinkListB = headB;
    int save_element{};
    while (LinkListA != LinkListB) {
        if (LinkListA == nullptr) {
            LinkListA = headB;
        }
        if (LinkListB == nullptr) {
            LinkListB = headA;
        }
        LinkListA = LinkListA->next;
        LinkListB = LinkListB->next;
    }
    save_element=LinkListA->element;

    return std::make_pair(save_element, LinkListA);
}
//fast and slow pointer for different velocity
std::pair<int,int> MiddleNode(Node* head) {
    if (head == nullptr) return std::make_pair(0, 0); //remind to check whether head is nullptr
    std::pair<int,int> middle_node;
    Node* fast = head;
    Node* slow = head;
    int counter{1};
    while (fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        counter++;
    }
    middle_node.first = slow->element;
    middle_node.second = counter;

    return middle_node;
}
//
// Created by unwan on 29/3/2026.
//
