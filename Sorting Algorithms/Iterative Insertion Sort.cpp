void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; ++i) {
        int curr = i;
        for(int j = i - 1; j >= 0; --j) {
            if(arr[j] >= arr[curr]) {
                int temp = arr[j];
                arr[j] = arr[curr];
                arr[curr] = temp;
                curr--;
            }
            else {
                break;
            }
        }
    }
}