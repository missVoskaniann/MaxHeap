#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>

class MaxHeap {
public:
    void insert(int key);
    int getMax();
    int extractMax();
    void increaseKey(int i, int key);
    void heapSort(std::vector<int>& arr);
    void print();
private:
    std::vector<int> heap;
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);

    void maxHeapify(std::vector<int>& arr, int i, int size);
    void buildMaxHeap(std::vector<int>& arr);

   
};

//void heapSort(std::vector<int>& arr);

#endif // MAXHEAP_H