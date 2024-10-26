// User function template for C++
class Solution {
  public:
    int check(vector <int> arr, long long mid) {
        if(arr[0] > arr[mid]) {
            return 1;
        }
        return 0;
    }
  
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        
        int start = 0, end = n - 1, ans = 0;
        
        while(start <= end) {
            long long mid = start + (end - start) / 2;
            if(check(arr, mid) == 1) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return ans;
    }
};