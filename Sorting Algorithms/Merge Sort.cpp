#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end) {
    int size1 = mid - end + 1;
    int size2 = end - mid;
    
    int *res = new int[size1 + size2];
    
    int i = start, j = mid + 1, idx = 0;
    
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            res[idx++] = arr[i++];
        }
        else {
            res[idx++] = arr[j++];
        }
    }
    
    while(i <= mid) {
        res[idx++] = arr[i++];
    }
    
    while(j <= end) {
        res[idx++] = arr[j++];
    } 
    
    for(int i = 0; i < size1 + size2; ++i) {
        arr[start + i] = res[i];
    }
    
    delete [] res;
}

void mergeSort(int arr[], int start, int end)
{
    // Base Case
    if(start == end) {
        return;
    }
    
    // Recursion Work
    int mid = start + (end - start) / 2;
    
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    
    
    // My Work
    merge(arr, start, mid, end);
}

int main() {
    int n;
    cin >> n;
    
    int *arr = new int[n];

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    delete [] arr;
}