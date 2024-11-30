class Solution {
public:
    int atMost(vector<int> nums, int goal) {
        int n = nums.size();
        int i = 0, j = 0, cnt = 0, sum = 0;

        if(goal < 0) {
            return 0;
        }

        while(j < n) {
            sum += nums[j];

            while(sum > goal) {
                sum -= nums[i];
                i++;
            }

            if(sum <= goal) {
                cnt += j - i + 1;
            }

            j++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res_k = atMost(nums, goal);
        int res_k_1 = atMost(nums, goal - 1);

        // Returning res_k - res_k_1, instead of res_k_1 - res_k, bcz res_k
        // cannot be negative even if goal is 0 But res_k > 0 and res_k_1 = 0,
        // so if we return res_k_1 - res_k then 0 - positive = -ve So that's why
        // we return like below
        return res_k - res_k_1;
    }
};