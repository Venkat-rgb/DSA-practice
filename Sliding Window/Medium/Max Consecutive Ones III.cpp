class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, zerosCnt = 0, maxi = 0;

        while(j < n) {
            if(nums[j] == 0) {
                zerosCnt++;
            }

            if(zerosCnt > k) {
                if(nums[i] == 0) {
                    zerosCnt--;
                }
                i++;
            }

            if(zerosCnt <= k) {
                maxi = max(maxi, j - i + 1);
            }

            j++;
        }

        return maxi;
    }
};