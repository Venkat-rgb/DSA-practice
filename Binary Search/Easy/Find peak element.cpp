// Time complexity: O(Logn)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        // Handling case where first element is peak
        if (nums[0] > nums[1]) {
            return 0;
        }

        // Handling case where last element is peak
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }

        // Starting search space 1 step forward, as we took care of checking
        // first and last elements if they are peak
        int start = 1, end = n - 2, ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid + 1]) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};