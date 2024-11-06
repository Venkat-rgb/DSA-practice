class Solution {
public:
    int check(vector <int> nums, int mid, int k) {
        int num_splits = 1, remaining_sum = mid;

        for(int i = 0; i < nums.size(); ++i) {
            if(remaining_sum >= nums[i]) {
                remaining_sum -= nums[i];
            }
            else {
                num_splits++;

                if(num_splits > k) {
                    return 0;
                }

                remaining_sum = mid;
                
                if(remaining_sum >= nums[i]) {
                    remaining_sum -= nums[i];
                }
                else {
                    return 0;
                }
            }
        }

        return num_splits <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, mini = INT_MAX;

        if(k > n) {
            return -1;
        }

        for(int i = 0; i < n; ++i) {
            mini = min(mini, nums[i]);
            sum += nums[i];
        }

        int start = mini, end = sum, ans = -1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(check(nums, mid, k) == 1) {
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