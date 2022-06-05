#include "CommonAlgorithms.hpp"
#include <iostream>
#include <memory>


int main(){

    int int_data[10] = {0,1,2,3,4,5,6,7,8,9};
    int index = binary_search<int>(int_data,6,10);
    std::cout<<"Data:"<<int_data<<'\n'<<"Index of "<<6<<" is "<<index<<'\n';
    index = binary_search<int>(int_data,11,10);
    std::cout<<"Data:"<<int_data<<'\n'<<"Index of "<<6<<" is "<<index<<'\n';

    int int_array[20] = {8,4,2,5,14,9,0,7,18,12};
    std::cout<<"Unsorted array: ";
    for(auto i: int_array)
        std::cout<<i<<' ';
    merge_sort(int_array,0,20);
    std::cout<<'\n';

    std::cout<<"Sorted array: ";
    for(auto i: int_array)
        std::cout<<i<<' ';
    std::cout<<'\n';

    // Quick Sort Usage
    int int_array_II[20] = {8,4,2,5,14,9,0,7,18,12};
    std::cout<<"Unsorted array: ";
    for(auto i: int_array_II)
        std::cout<<i<<' ';
    quick_sort(int_array_II,0,20);
    std::cout<<'\n';

    std::cout<<"Sorted array: ";
    for(auto i: int_array_II)
        std::cout<<i<<' ';
    std::cout<<'\n';

}

