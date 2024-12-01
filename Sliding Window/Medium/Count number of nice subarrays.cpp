class Solution {
public:
    int atMost(vector <int> nums, int k) {
        int n = nums.size(), cnt = 0, res = 0;
        int i = 0, j = 0;

        if(k < 0) return 0;

        while(j < n) {
            if(nums[j] % 2 == 1) {
                cnt++;
            }

            while(cnt > k) {
                if(nums[i] % 2 == 1) {
                    cnt--;
                }
                i++;
            }

            if(cnt <= k) {
                res += j - i + 1;
            }
            j++;
        }

        return res;
    } 

    int numberOfSubarrays(vector<int>& nums, int k) {
        int res_k = atMost(nums, k);
        int res_k_1 = atMost(nums, k - 1);

        return res_k - res_k_1;
    }
};