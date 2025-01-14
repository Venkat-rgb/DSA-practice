// Time complexity: O(2logN)
// Space complexity: O(1)
int count(int arr[], int n, int x) {
    auto lower = lower_bound(arr, arr + n, x);
    auto upper = upper_bound(arr, arr + n, x);
    
    int firstOcc = lower - arr;
    int lastOcc = upper - arr;
    
    return lastOcc - firstOcc;
}