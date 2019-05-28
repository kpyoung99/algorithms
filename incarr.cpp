/*Increment a dynamically allocated array*/
#include <iostream>
void arr_inc(int*, int);

int main(){
    //Initialize array
    int *arr;
    arr = new int[10];
    for (int i = 0; i < 10; ++i) arr[i] = i;
    
    //Print contents
    for (int i = 0; i < 10; ++i) std::cout << arr[i] << ", ";
    std::cout << std::endl;

    arr_inc(arr, 10);

    //Print results
    for (int i = 0; i < 10; ++i) std::cout << arr[i] << ", ";
    std::cout << std::endl;

    delete[] arr;
    return 0;
}

void arr_inc(int *arr, int n){
    for (int i = 0; i < n; ++i){
        arr[i] += 1;
    }
}