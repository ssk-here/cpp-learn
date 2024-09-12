#ifndef HEAP_H
#define HEAP_H

class Heap {
public:
    Heap(int capacity = 10);
    virtual ~Heap();
    void insert(const int &key);
    int erase();
    int peek() const;
    int size() const;
    bool empty() const;
    void resize(int new_capacity);
    void print();
    void swap(int& a, int& b);
    int parent(int x) const;
    bool isLeftNode(int index);
    virtual void HeapifyUp(int index) = 0; // Pure virtual function
    virtual void HeapifyDown(int index) = 0; // Pure virtual function
    protected:
    int* heap;
    int capacity;
    int sz, temp;
};;

class MaxHeap :public Heap {
public:
    MaxHeap(int capacity = 10);
    ~MaxHeap();
    void HeapifyUp(int index) override;
    void HeapifyDown(int index) override;
};

class MinHeap :public Heap {
public:
    MinHeap(int capacity = 10);
    ~MinHeap();
    void HeapifyUp(int index) override;
    void HeapifyDown(int index) override;
};

#endif // HEAP_H
