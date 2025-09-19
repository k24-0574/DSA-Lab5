#include <iostream>
using namespace std;

int rowSum(int *arr, int size){
    if(size==0) return 0;
    return arr[size-1] + rowSum(arr, size-1);
}

int recursiveArraySum(int* arr[], int sizes[], int dim){
    if(dim==0) return 0;
    return rowSum(arr[dim-1], sizes[dim-1])+ recursiveArraySum(arr, sizes, dim-1);
}

int main(){
    int sizes[] = {2, 3, 4};

    int arr1[] = {1, 2};
    int arr2[] = {3, 4, 5};
    int arr3[] = {6, 7, 8, 9};

    int *arr[3] = {arr1, arr2, arr3};

    int sum = recursiveArraySum(arr, sizes, 3);
    cout<<sum;

    return 0;
}