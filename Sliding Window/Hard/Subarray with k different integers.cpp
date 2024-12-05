class Solution {
public:
    int atMost(vector <int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        int i = 0, j = 0;
        unordered_map <int, int> mp;

        if(k < 0) return 0;

        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            if(mp.size() <= k) {
                cnt += j - i + 1;
            }

            j++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res_k = atMost(nums, k);
        int res_k_1 = atMost(nums, k - 1);

        return res_k - res_k_1;
    }
};