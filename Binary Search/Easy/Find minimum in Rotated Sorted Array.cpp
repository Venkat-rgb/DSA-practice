// Time complexity: O(LogN)
class Solution {
public:
    int check(vector <int> nums, int mid) {
        if(nums[0] > nums[mid]) {
            return 1;
        }
        return 0;
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();

        int start = 0, end = n - 1, ans = 0;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(check(nums, mid) == 1) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        
        return nums[ans];
    }
};