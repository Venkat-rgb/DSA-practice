class Solution {
public:
    void helper(vector<int>& candidates, int start, int target,
                vector<int> &temp, vector<vector<int>>& res) {
        // 1) Base case
        if(target == 0) {
            res.push_back(temp);
            return;
        }

        if(start == candidates.size()) {
            return;
        }

        // 2) Recursion work
        // Pick
        if(candidates[start] <= target) {
            temp.push_back(candidates[start]);
            helper(candidates, start, target - candidates[start], temp, res);

            // Remove
            temp.pop_back();
        }

        helper(candidates, start + 1, target, temp, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        helper(candidates, 0, target, temp, res);

        return res;
    }
};