// Time complexity: O(LogN)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        // Handling case where first element is unique
        if (nums[0] != nums[1]) {
            return nums[0];
        }

        // Handling case where last element is unique
        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        int start = 1, end = n - 2;

        // Decreased the search space 1 step, inorder to avoid writing multiple
        // conditions for first and last elements
        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            } else if (nums[mid] == nums[mid - 1]) {
                if ((mid - 1) % 2 == 0) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else if (nums[mid] == nums[mid + 1]) {
                if (mid % 2 != 0) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }

        return -1;
    }
};