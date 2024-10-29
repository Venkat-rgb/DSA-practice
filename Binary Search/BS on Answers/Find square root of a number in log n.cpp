// Function to find square root
// x: element to find square root
class Solution {
  public:
    int check(long long mid, int n) {
        if((long long)mid * mid >= n) {
            return 1;
        }
        
        return 0;
    }
  
    long long int floorSqrt(long long int n) {
        int start = 1, end = n, ans = -1;
        
        while(start <= end) {
            long long mid = start + (end - start) / 2;
            
            if(check(mid, n) == 1) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return (long long)ans * ans != n ? ans - 1 : ans;
    }
};