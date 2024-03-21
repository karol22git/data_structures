#include "MyAlgorithms.hpp"

template <typename T>
int Partition(T array[],int lower_index, int higher_index) {
    T pivot = array[higher_index];
    int i = lower_index-1;
    for(int j = lower_index ; j < higher_index ; ++j) {
        if(array[j] <= pivot) {
            i = i+1;
            T tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    int tmp = array[i+1];
    array[i+1] = array[higher_index];
    array[higher_index] = tmp;
    return i+1;
}

template <typename T>
void MyAlgorithms::QuickSort(T array[], int index, int array_size) {
    if(index < array_size) {
        int pivot = Partition(array,index,array_size);
        QuickSort(array, index, pivot - 1);
        QuickSort(array, pivot + 1, array_size);
    }
}
template void MyAlgorithms::QuickSort<int>(int array[],int index,int array_size);
