#include <iostream>


namespace MyAlgorithms {
    template <typename T>
    void InsertionSort(T array[],int array_size);
    
    template <typename T>
    void PrintArray(T array[],int array_size);

}

template <typename T>
void MyAlgorithms::PrintArray(T array[],int array_size) { 
    for(int i = 0 ; i < array_size ; ++i) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
}
template void MyAlgorithms::PrintArray<int>(int array[],int array_size);
