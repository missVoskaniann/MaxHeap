#include "maxHeap.h"

#include <vector>
#include <iostream>

int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

int MaxHeap::leftChild(int i) {
    return 2 * i + 1;
}

int MaxHeap::rightChild(int i) {
    return 2 * i + 2;
}

void MaxHeap::maxHeapify(std::vector<int>& arr, int i, int size) {
    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, size);
    }
}

void MaxHeap::buildMaxHeap(std::vector<int>& arr) {
    heap = arr;
    for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
        maxHeapify(heap, i, heap.size());
    }
}

int MaxHeap::extractMax() {
    if (heap.empty()) {
        std::cerr << "Heap is empty!" << std::endl;
        return -1;
    }

    int max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    maxHeapify(heap, 0, heap.size()); 
    return max;
}

void MaxHeap::insert(int key) {
    heap.push_back(key);

    int i = heap.size() - 1;
    while (i > 0 && heap[i] > heap[parent(i)]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::getMax() {
    if (heap.empty()) {
        std::cerr << "Heap is empty!" << std::endl;
        return -1;
    }
    return heap[0];
}



void MaxHeap::increaseKey(int i, int key) {
    if (key < heap[i]) {
        std::cerr << "New key is smaller than current key!" << std::endl;
        return;
    }

    heap[i] = key;
    while (i > 0 && heap[i] > heap[parent(i)]) {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::print() {
    for (int i : heap) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void MaxHeap::heapSort(std::vector<int>& arr) {
    buildMaxHeap(arr);

    for (int i = arr.size() - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}


