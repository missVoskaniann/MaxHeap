#include "maxHeap.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {12, 11, 14, 4, 2, 7};

    MaxHeap m;
    for (int key : arr) {
        m.insert(key);
    }

    std::cout << "Max Heap: ";
    m.print();
    std::cout << "Get Max: " << m.getMax() << std::endl;
    std::cout << "Extract Max: " << m.extractMax() << std::endl;
    std::cout << "Max Heap after extraction: ";
    m.print();

    m.insert(15);
    std::cout << "Max Heap after insertion: ";
    m.print();

    m.increaseKey(2, 20);
    std::cout << "Max Heap after increasing key: ";
    m.print();

    m.heapSort(arr);
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}