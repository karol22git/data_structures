#include "MyAlgorithms.hpp"
#include<iostream>

template <typename T>
void MyAlgorithms::InsertionSort(T array[], int array_size) {
    
    for(int i = 1; i < array_size ; ++i) {
        T key = array[i];
        int index = i-1;
        while(index >= 0 && array[index] > key) {
            array[index + 1] = array[index];
            index = index  - 1;
        }
        array[index+1] = key;
    }
}
template void MyAlgorithms::InsertionSort<int>(int array[],int array_size);
