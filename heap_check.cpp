#include "heap.h"
#include <iostream>
#include <cassert>

class TestMinHeap {
public:
    void testMinHeapConstructor() {
        MinHeap heap(10);
        assert(heap.size() == 0);
        assert(heap.empty());
        std::cout << "testMinHeapConstructor passed!" << std::endl;
    }

    void testPrint() {
        MinHeap heap(10);
        for(int i = 0; i < 20; i++)
            heap.insert(i);
        heap.print();
        assert(heap.size() == 20);
        std::cout << "testPrint passed!" << std::endl;
    }

    void testInsertAndPeek() {
        MinHeap heap(10);
        heap.insert(5);
        assert(heap.peek() == 5);
        heap.insert(3);
        assert(heap.peek() == 3);
        heap.insert(8);
        assert(heap.peek() == 3);
        std::cout << "testInsertAndPeek passed!" << std::endl;
    }

    void testDeleteMin() {
        MinHeap heap(10);
        heap.insert(5);
        heap.insert(3);
        heap.insert(8);
        assert(heap.erase() == 3);
        assert(heap.erase() == 5);
        assert(heap.erase() == 8);
        std::cout << "testDeleteMin passed!" << std::endl;
    }

    void testResize() {
        MinHeap heap(2);
        heap.insert(5);
        heap.insert(3);
        heap.insert(8); // Should trigger resize
        assert(heap.size() == 3);
        assert(heap.peek() == 3);
        std::cout << "testResize passed!" << std::endl;
    }

    void testHeapifyUp() {
        MinHeap heap(10);
        heap.insert(10);
        heap.insert(20);
        heap.insert(5);
        assert(heap.peek() == 5);
        std::cout << "testHeapifyUp passed!" << std::endl;
    }

    void testHeapifyDown() {
        MinHeap heap(10);
        heap.insert(5);
        heap.insert(10);
        heap.insert(20);
        heap.erase();
        assert(heap.peek() == 10);
        std::cout << "testHeapifyDown passed!" << std::endl;
    }

    void testEmpty() {
        MinHeap heap(10);
        assert(heap.empty());
        heap.insert(1);
        assert(!heap.empty());
        std::cout << "testEmpty passed!" << std::endl;
    }
    void Test(){
        testPrint();
        testMinHeapConstructor();
        testInsertAndPeek();
        testDeleteMin();
        testResize();
        testHeapifyUp();
        testHeapifyDown();
        testEmpty();
        std::cout << "All tests passed!" << std::endl;
    }
};
class TestMaxHeap {
public:
    void testMaxHeapConstructor() {
        MaxHeap heap(10);
        assert(heap.size() == 0);
        assert(heap.empty());
        std::cout << "testMaxHeapConstructor passed!" << std::endl;
    }

    void testPrint() {
        MaxHeap heap(10);
        for(int i = 0; i < 20; i++)
            heap.insert(i);
        heap.print();
        assert(heap.size() == 20);
        std::cout << "testPrint passed!" << std::endl;
    }

    void testInsertAndPeek() {
        MaxHeap heap(10);
        heap.insert(5);
        assert(heap.peek() == 5);
        heap.insert(3);
        assert(heap.peek() == 5);
        heap.insert(8);
        assert(heap.peek() == 8);
        std::cout << "testInsertAndPeek passed!" << std::endl;
    }

    void testDeleteMax() {
        MaxHeap heap(10);
        heap.insert(5);
        heap.insert(3);
        heap.insert(8);
        assert(heap.erase() == 8);
        assert(heap.erase() == 5);
        assert(heap.erase() == 3);
        std::cout << "testDeleteMax passed!" << std::endl;
    }

    void testResize() {
        MaxHeap heap(2);
        heap.insert(5);
        heap.insert(3);
        heap.insert(8); // Should trigger resize
        assert(heap.size() == 3);
        assert(heap.peek() == 8);
        std::cout << "testResize passed!" << std::endl;
    }

    void testHeapifyUp() {
        MaxHeap heap(10);
        heap.insert(10);
        heap.insert(20);
        heap.insert(5);
        assert(heap.peek() == 20);
        std::cout << "testHeapifyUp passed!" << std::endl;
    }

    void testHeapifyDown() {
        MaxHeap heap(10);
        heap.insert(20);
        heap.insert(10);
        heap.insert(5);
        heap.erase();
        assert(heap.peek() == 10);
        std::cout << "testHeapifyDown passed!" << std::endl;
    }

    void testEmpty() {
        MaxHeap heap(10);
        assert(heap.empty());
        heap.insert(1);
        assert(!heap.empty());
        std::cout << "testEmpty passed!" << std::endl;
    }
    void Test(){
        testPrint();
        testMaxHeapConstructor();
        testInsertAndPeek();
        testDeleteMax();
        testResize();
        testHeapifyUp();
        testHeapifyDown();
        testEmpty();
        std::cout << "All tests passed!" << std::endl;
    }
};

int main() {
    TestMinHeap().Test();
    TestMaxHeap().Test();
    return 0;
}
/*
advantages of tree implementation over array
Certainly! Let's explore the advantages of using a **tree-based structure** (such as a binary heap) over a simple **array** for implementing a **min heap**:

1. **Dynamic Size:**
   - Trees allow dynamic resizing without the need to preallocate a fixed-size array.
   - As elements are inserted or removed, the tree structure can grow or shrink dynamically.

2. **Efficient Insertion and Deletion:**
   - In a binary heap (implemented as a tree), insertion and deletion operations have logarithmic time complexity (O(log n)).
   - In contrast, resizing an array (when it's full) involves copying all existing elements, which can be less efficient.

3. **No Need for Continuous Memory Block:**
   - Trees do not require a continuous memory block like arrays do.
   - This flexibility allows for better memory management and fragmentation avoidance.

4. **Ease of Implementation:**
   - Implementing a binary heap using a tree-based structure is conceptually simpler than managing an array with manual resizing.
   - The tree structure naturally maintains the heap property.

5. **Better for Priority Queues:**
   - Priority queues (often implemented using heaps) benefit from tree-based structures.
   - Trees allow efficient insertion and removal of elements while maintaining the heap property.

6. **Space Efficiency:**
   - Trees use less memory compared to arrays, especially when the heap is not full.
   - Trees avoid wasting memory on unused slots.

In summary, while arrays have their advantages (such as cache locality and simplicity), tree-based structures (like binary heaps) are more suitable for dynamic data management, efficient insertion/deletion, and priority queue implementations. 😊
[GeeksforGeeks](https://www.geeksforgeeks.org/advantages-of-heap-over-sorted-array/) provides additional details on this topic if you'd like to explore further¹. And hey, even AI assistants have their moments of code typos! 🤖🙃

Source: Conversation with Copilot, 12/9/2024
(1) Introduction to Min-Heap Data Structure - GeeksforGeeks. https://www.geeksforgeeks.org/introduction-to-min-heap-data-structure/.
(2) Data Structures 101: How to build min and max heaps - Educative. https://www.educative.io/blog/data-structure-heaps-guide.
(3) Applications, Advantages and Disadvantages of Heap. https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-heap/.
(4) Heap Data Structure - GeeksforGeeks. https://www.geeksforgeeks.org/heap-data-structure/.
(5) Heap implementation in Java - GeeksforGeeks. https://www.geeksforgeeks.org/heap-implementation-in-java/.
*/

/*
Certainly! Let's explore the advantages of using an **array-based implementation** over a tree-based structure (such as a binary heap) for certain scenarios. While both approaches have their merits, here are some advantages of using arrays:

1. **Efficient Element Access:**
   - Arrays provide **constant-time** access to elements by index.
   - You can directly access any element using its position in the array.
   - This efficiency is especially beneficial when you need to access elements frequently.

2. **Simplicity and Predictability:**
   - Array-based implementations are straightforward and easy to understand.
   - The fixed memory layout ensures predictable behavior.
   - Arrays are widely used due to their simplicity.

3. **Cache Locality:**
   - Elements in an array are stored in contiguous memory locations.
   - This improves cache locality, leading to faster memory access.
   - Cache-friendly behavior is crucial for performance optimization.

4. **Space Efficiency:**
   - Arrays use less memory compared to tree-based structures.
   - Trees require additional memory for pointers or node structures.
   - Arrays avoid this overhead.

5. **Random Access and Indexing:**
   - Arrays allow random access to elements.
   - You can efficiently retrieve or modify any element by its index.

6. **Fixed Size and Deterministic Behavior:**
   - Arrays have a fixed size determined at compile time.
   - This predictability simplifies memory management.

However, it's essential to consider the trade-offs. Arrays have limitations, such as fixed size and expensive insertions/deletions. For dynamic data structures (like priority queues), tree-based structures (e.g., binary heaps) are often more suitable. Choose the right tool for the job based on your specific requirements! 😊
[Learn more](https://www.geeksforgeeks.org/advantages-and-disadvantages-of-array-in-c/) about the advantages and disadvantages of arrays in C++ if you'd like additional details⁴. And hey, even AI assistants have their moments of code typos! 🤖🙃

Source: Conversation with Copilot, 12/9/2024
(1) Advantages and Disadvantages of Array in C - GeeksforGeeks. https://www.geeksforgeeks.org/advantages-and-disadvantages-of-array-in-c/.
(2) Binary Tree (Array implementation) - GeeksforGeeks. https://www.geeksforgeeks.org/binary-tree-array-implementation/.
(3) Lecture 9: More on Trees 1 Array Implementations of Trees: Pros and .... https://piazza.com/class_profile/get_resource/h63tokvn98219n/h7btvlhumtn6gc.
(4) What are the Advantages and Disadvantages of Arrays?. https://www.prepbytes.com/blog/arrays/advantages-and-disadvantages-of-arrays/.
(5) Array Representation of Binary Tree. https://www.prepbytes.com/blog/tree/array-representation-of-binary-tree/.
*/