// Time complexity: O(2^N)
class Solution {
public:
    void helper(int start, int end, int sum, int target, vector<int>& temp,
                vector<vector<int>>& res) {
        // 1) Base case
        if(sum == target) {
            res.push_back(temp);
            return;
        }

        if(start == end + 1 || sum >= target) {
            return;
        }

        // 2) Recursion work
        // (i) Pick
        temp.push_back(start);
        sum += start;
        helper(start + 1, end, sum, target, temp, res);

        // (ii) Remove
        temp.pop_back();
        sum -= start;
        helper(start + 1, end, sum, target, temp, res);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res, ans;
        vector<int> temp;
        helper(1, 9, 0, n, temp, res);

        for(int i = 0; i < res.size(); ++i) {
            if(res[i].size() == k) {
                ans.push_back(res[i]);
            }
        }

        return ans;
    }
};