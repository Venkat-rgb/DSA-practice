class Solution {
public:
    void helper(vector<int> &candidates, int start, int sum, int target,
                vector<int> &temp, vector<vector<int>>& res) {
        // 1) Base case
        if(sum == target) {
            res.push_back(temp);
            return;
        }
        
        if(start == candidates.size() || sum > target) {
            return;
        }

        // 2) Recursion work + My work
        // (i) Pick
        temp.push_back(candidates[start]);
        sum += candidates[start];
        helper(candidates, start + 1, sum, target, temp, res);

        // (ii) Remove
        temp.pop_back();
        sum -= candidates[start];

        // Removing duplicates
        while(start + 1 < candidates.size() && candidates[start] == candidates[start + 1]) {
            start++;
        }

        helper(candidates, start + 1, sum, target, temp, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        helper(candidates, 0, 0, target, temp, res);

        return res;
    }
};