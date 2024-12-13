class Solution {
public:
    void helper(vector <int> &nums, int start, vector <int> temp, vector<vector<int>> &res) {
        // 1) Base case
        if(start == nums.size()) {
            res.push_back(temp);
            return;
        }

        // 2) Recursion work
        // Pick
        temp.push_back(nums[start]);
        helper(nums, start + 1, temp, res);

        // Remove
        temp.pop_back();

        // Removing the duplicates
        while(start + 1 < nums.size() && nums[start] == nums[start + 1]) {
            start++;
        }

        helper(nums, start + 1, temp, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector <vector<int>> res;
        vector <int> temp;
        sort(nums.begin(), nums.end());
        helper(nums, 0, temp, res);
        return res;
    }
};