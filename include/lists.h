#ifndef LISTS_H
#define LISTS_H

#include <vector>
#include <iostream>
#include <cassert> // Include this header for assert

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x);
};

// LinkedList class with utility functions.
class LinkedList {
public:
    // Function to convert a linked list to a vector.
    std::vector<int> listToVector(ListNode* head);

    // Function to convert a vector to a linked list.
    ListNode* vectorToList(const std::vector<int>& vec);

    // Function to print the linked list.
    void printList(ListNode* head);
};

#endif // LISTS_H
