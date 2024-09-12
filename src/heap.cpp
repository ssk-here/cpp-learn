#include "heap.h"
#include <new>       // For std::bad_alloc
#include <iostream>  // For std::cerr
#include <assert.h>
#include <climits>
/**
 * @brief Constructs a MinHeap with a given capacity.
 * 
 * This constructor initializes the heap with the specified capacity.
 * If memory allocation fails, it catches the std::bad_alloc exception,
 * logs an error message, and re-throws the exception.
 * 
 * @param capacity The maximum number of elements the heap can hold.
 * 
 * @throws std::bad_alloc if memory allocation fails.
 */
Heap::Heap(int capacity) : capacity(capacity), sz(0) {
    try {
        heap = new int[capacity];
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory capacity reached-heap size=: " << sz << std::endl;
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        throw; // Re-throw the exception after logging
    }
}

Heap::~Heap() {
    // Destructor implementation
    delete[] heap;
    sz = 0;
}

void Heap::insert(const int &key) {
    // Insert implementation
    if(sz == capacity)
        resize(2*capacity);
    heap[sz] = key;
    sz++;
    if(sz>1)
        HeapifyUp(parent(sz-1));
}

int Heap::parent(int x) const{
    //ensure x is > 0.
    assert(x > 0);
    return (x-1)/2;
}

int Heap::erase() {
    // Delete implementation
    int m = heap[0];
    sz--;
    if(sz>0){
        heap[0] = heap[sz];
        HeapifyDown(0);
    }
    return m;
}

int Heap::peek() const {
    // Peek implementation
    if(sz==0)
        return INT_MAX;
    return heap[0];
}

int Heap::size() const {
    // Size implementation
    return sz;
}

bool Heap::empty() const {
    // Empty implementation
    return (sz==0);
}

void Heap::resize(int new_capacity) {
    // Resize implementation
    int* new_heap = nullptr;
    try {
        new_heap = new int[new_capacity];
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory capacity reached-heap size=: " << sz << std::endl;
        std::cerr << "Memory allocation failed during resize: " << e.what() << std::endl;
        throw; // Re-throw the exception after logging
    }

    for (int i = 0; i < sz; ++i) {
        new_heap[i] = heap[i];
    }

    delete[] heap;
    heap = new_heap;
    capacity = new_capacity;
}

void Heap::swap(int& a, int& b) {
    // Swap implementation
    temp = a;
    a = b;
    b = temp;
}

bool Heap::isLeftNode(int index){
    //checks if it is leftmost node.
    //index + 1 should be a power of 2.
    index++;
    index = index & (index-1);
    return (index == 0);
}

void Heap::print(){
    for(int i=0;i<sz;i++){
        if(isLeftNode(i))
            std::cout<<std::endl;
        std::cout<<heap[i]<<" ";
    }
    std::cout<<std::endl;
}

MaxHeap::MaxHeap(int capacity) : Heap(capacity) {
    // Constructor implementation
}

MaxHeap::~MaxHeap() {
    // Destructor implementation
}

MinHeap::MinHeap(int capacity) : Heap(capacity) {
    // Constructor implementation
}

MinHeap::~MinHeap() {
    // Destructor implementation
}


void MinHeap::HeapifyUp(int index) {
    // HeapifyUp implementation -index is parent
    // std::cout<<"heapifyup at index- "<<index<<std::endl;
    // print();
    int l = 2*index +1, r = 2*index +2;
    bool stopheapify = true;
    if(l<sz && heap[l] < heap[index]){
        swap(heap[l],heap[index]);
        stopheapify = false;
    }
    if(r<sz && heap[r] < heap[index]){
        swap(heap[r],heap[index]);
        stopheapify = false;
    }
    if(stopheapify)
        return;
    if(index)
        HeapifyUp(parent(index));
}

void MinHeap::HeapifyDown(int index) {
    // HeapifyDown implementation -index is parent
    if(2*index + 1 >= sz)//leaf nodes
        return;
    int l = 2*index +1,r =2*index +2;
    if(l<sz && heap[l] < heap[index]){
        swap(heap[l],heap[index]);
        HeapifyDown(l);
    }
    if(r<sz && heap[r] < heap[index]){
        swap(heap[r],heap[index]);
        HeapifyDown(r);
    }
}



void MaxHeap::HeapifyUp(int index) {
    // HeapifyUp implementation -index is parent
    // std::cout<<"heapifyup at index- "<<index<<std::endl;
    // print();
    int l = 2*index +1, r = 2*index +2;
    bool stopheapify = true;
    if(l<sz && heap[l] > heap[index]){
        swap(heap[l],heap[index]);
        stopheapify = false;
    }
    if(r<sz && heap[r] > heap[index]){
        swap(heap[r],heap[index]);
        stopheapify = false;
    }
    if(stopheapify)
        return;
    if(index)
        HeapifyUp(parent(index));
}

void MaxHeap::HeapifyDown(int index) {
    // HeapifyDown implementation -index is parent
    if(2*index + 1 >= sz)//leaf nodes
        return;
    int l = 2*index +1,r =2*index +2;
    if(l<sz && heap[l] > heap[index]){
        swap(heap[l],heap[index]);
        HeapifyDown(l);
    }
    if(r<sz && heap[r] > heap[index]){
        swap(heap[r],heap[index]);
        HeapifyDown(r);
    }
}
