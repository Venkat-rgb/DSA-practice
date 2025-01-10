// Time complexity: O(N^2)
void bubbleSort(int arr[], int n) {
    // Base case
    if(n <= 1) {
        return;
    }
    
    // My work
    for(int i = 0; i < n - 1; ++i) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    
    // Recursion work
    bubbleSort(arr, n - 1);
}