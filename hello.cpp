#include <iostream>
#include <vector>
#include <string>
#include "lists.h"

using namespace std;

int main()
{
    vector<int> values;
    int input;

    cout << "Enter 5 values:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> input;
        values.push_back(input);
    }
    LinkedList L;
    ListNode *head = L.vectorToList(values);
    cout<<"Linked List is ";
    L.printList(head);
   
    cout << endl;
}
