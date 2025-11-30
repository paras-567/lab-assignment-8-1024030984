#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool sortAscending) {
    int root = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(sortAscending) {
        if(left<n&&arr[left]>arr[root])
            root = left;
        if(right<n&&arr[right]>arr[root])
            root = right;
    } else {
        if(left<n&&arr[left]<arr[root])
            root = left;
        if(right<n&&arr[right]<arr[root])
            root = right;
    }

    if(root!=i) {
        int temp = arr[i];
        arr[i] = arr[root];
        arr[root] = temp;
        heapify(arr, n, root, sortAscending);
    }
}

void heapSort(int arr[], int n, bool sortAscending) {
    for(int i=n/2-1;i>=0;i--)
        heapify(arr, n, i, sortAscending);

    for(int i=n-1;i>0;i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, sortAscending);
    }
}

void printArray(int arr[], int n) {
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    cout<<"Original array: ";
    printArray(arr1, n1);

    heapSort(arr1, n1, true);
    cout<<"Sorted Increasing: ";
    printArray(arr1, n1);

    int arr2[] = {9, 4, 1, 8, 3, 2};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout<<"\nOriginal array: ";
    printArray(arr2, n2);

    heapSort(arr2, n2, false);
    cout<<"Sorted Decreasing: ";
    printArray(arr2, n2);

    return 0;
}