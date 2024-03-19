#include "MyAlgorithms.hpp"
#include <cmath>

int left(int i) {
    return 2*i +1;
}

int right(int i) {
    return 2*i+2;
}

int parent(int i) {
    return std::floor(i/2);
}


template <typename T>
void MaxHeapify(T array[], int i, int array_size) {
    int left_son = left(i);
    int right_son = right(i);
    int heap_size = array_size-1;
    int largest;
    if(left_son <= heap_size && array[left_son] > array[i]) {
        largest = left_son;
    }
    else {
        largest = i;
    }
    if(right_son <= heap_size && array[right_son] > array[largest]) {
        largest = right_son;
    }
    if(largest != i) {
        T tmp = array[i];
        array[i] = array[largest];
        array[largest] = tmp;
        MaxHeapify(array,largest,array_size);
    }
}

template <typename T>
void BuildMaxHeap(T array[],int array_size) {
    for(int i = array_size/2 - 1 ; i>= 0; --i) {
        MaxHeapify(array,i,array_size);
    }
}

template <typename T>
void MyAlgorithms::HeapSort(T array[],int array_size) {
    int heap_size = array_size;
    BuildMaxHeap(array,heap_size);
    for(int i = array_size-1 ; i >=0; --i) {
        T tmp = array[i];
        array[i] = array[0];
        array[0] = tmp; 
        heap_size = heap_size - 1;
        MaxHeapify(array,0,heap_size);
    }
}
template void MyAlgorithms::HeapSort<int>(int array[],int array_size);


