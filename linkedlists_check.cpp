#include "lists.h"
#include <cassert>
#include <iostream>
#include <vector>

void runTestCase(LinkedList& list, const std::vector<int>& inputVec, int nodeIndexToDelete, const std::vector<int>& expectedVec, const std::string& testCaseName) {
    std::cout << testCaseName << " Executing ";
    ListNode* head = list.vectorToList(inputVec);
    ListNode* nodeToDelete = head;
    for (int i = 0; i < nodeIndexToDelete; ++i) {
        nodeToDelete = nodeToDelete->next;
    }
    list.DeleteNode(head, nodeToDelete);
    std::vector<int> result = list.listToVector(head);
    std::cout << testCaseName << " - Result: ";
    for (int val : result) std::cout << val << " ";
    std::cout << "\nExpected: ";
    for (int val : expectedVec) std::cout << val << " ";
    std::cout << std::endl;
}

void testDeleteNode() {
    LinkedList list;
    // Test case 1: Delete node at the beginning
    runTestCase(list, {1, 2, 3, 4, 5}, 0, {2, 3, 4, 5}, "Test case 1");

    // Test case 2: Delete node in the middle
    runTestCase(list, {1, 2, 3, 4, 5}, 2, {1, 2, 4, 5}, "Test case 2");

    // Test case 3: Delete node at the end
    runTestCase(list, {1, 2, 3, 4, 5}, 4, {1, 2, 3, 4}, "Test case 3");

    // Test case 4: Delete node in a single-element list
    runTestCase(list, {1}, 0, {}, "Test case 4");

    // Test case 5: Delete node in a two-element list
    runTestCase(list, {1, 2}, 0, {2}, "Test case 5");

    std::cout << "All test cases executed!" << std::endl;
}
class HitCounter {
public:
    map<int,int> T;
    priority_queue<int, vector<int> , greater<int> > pq;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        if(T.find(timestamp) != T.end())
            T[timestamp]++;
        else{
            pq.push(timestamp);
            T[timestamp] =1;
        }
    }
    
    int getHits(int timestamp) {
       
        int ans =0;
        for(auto it = M.begin()+pos; it>M.begin(); it--){
            if(timestamp - it->first <= 300)
                ans += it->second;
            else
                break;
        }
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
int main() {
    testDeleteNode();
    return 0;
}
