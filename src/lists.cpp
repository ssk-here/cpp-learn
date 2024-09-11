#include "lists.h"

// Constructor for ListNode
ListNode::ListNode(int x) : val(x), next(nullptr) {}

// Function to convert a linked list to a vector.
std::vector<int> LinkedList::listToVector(ListNode* head) {
    std::vector<int> result;
    ListNode* current = head;
    while (current != nullptr) {
        result.push_back(current->val);
        current = current->next;
    }
    return result;
}

// Function to convert a vector to a linked list.
ListNode* LinkedList::vectorToList(const std::vector<int>& vec) {
    if (vec.empty()) return nullptr;
    ListNode* head = new ListNode(vec[0]);
    assert(head != nullptr);
    ListNode* current = head;
    for (size_t i = 1; i < vec.size(); ++i) {
        current->next = new ListNode(vec[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list.
void LinkedList::printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        current = current->next;
        if(current) {
            std::cout << "->";
        }
    }
    std::cout << "-X";
    std::cout << std::endl;
}