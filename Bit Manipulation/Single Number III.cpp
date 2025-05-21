// Time Complexity: O(N)
// Space complexity: O(1)
class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            int n = nums.size();
            long long res = 0;
    
            for(int i = 0; i < n; ++i) {
                res ^= nums[i];
            }
    
            long long pos = log2(res & -res);
            int group1Xor = 0, group2Xor = 0;
    
            for(int i = 0; i < n; ++i) {
                long long mask = nums[i] & (1 << pos);
                if(mask != 0) {
                    group1Xor ^= nums[i];
                }
                else {
                    group2Xor ^= nums[i];
                }
            }
    
            return {group1Xor, group2Xor};
        }
    };