// Time complexity: O(N^2)
// Space complexity: O(1)
void selectionSort(int arr[], int n) {
    for(int i = 0; i < n; ++i) {
        int mini = INT_MAX, minIdx = -1;
        for(int j = i; j < n; ++j) {
            if(arr[j] < mini) {
                mini = arr[j];
                minIdx = j;
            } 
        }
        swap(arr[i], arr[minIdx]);
    }
}