class Solution {
public:
    // Approach - 1(First generating permutation from index 1 to n, and adding arr[0] at each of the index)
    void helper(vector <int> &nums, int start, vector<vector<int>> &res) {
        // 1) Base case
        if(start == nums.size()) {
            res.push_back({});
            return;
        }

        // 2) Recursion work
        vector<vector<int>> temp;
        helper(nums, start + 1, temp);

        // 3) My work
        for(int i = 0; i < temp.size(); ++i) {
            for(int j = 0; j <= temp[i].size(); ++j) {
                vector <int> ans = temp[i];
                ans.insert(ans.begin() + j, nums[start]);
                res.push_back(ans);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector<int>> res;
        helper(nums, 0, res);
        return res;
    }
};