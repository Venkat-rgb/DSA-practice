class Solution {
public:
    int check(vector <int> nums, int mid, int threshold) {
        long long sum = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            sum += ceil(nums[i] / (mid + 0.0));
        }

        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), maxi = INT_MIN;

        if(n > threshold) return -1;

        for(int i = 0; i < n; ++i) {
            maxi = max(maxi, nums[i]);
        }

        int start = 1, end = maxi, ans = -1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(check(nums, mid, threshold) == 1) {
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