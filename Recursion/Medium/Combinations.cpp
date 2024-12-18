class Solution {
public:
    void helper(int start, int end, vector <int> &temp, vector<vector<int>> &res) {
        // 1) Base case
        if(start == end + 1) {
            res.push_back(temp);
            return;
        }

        // 2) Recursion work
        // (i) Pick
        temp.push_back(start);
        helper(start + 1, end, temp, res);

        // (ii) Remove
        temp.pop_back();
        helper(start + 1, end, temp, res);
    }

    vector<vector<int>> combine(int n, int k) {
        vector <vector<int>> res, ans;
        vector <int> temp;
        helper(1, n, temp, res);
    
        for(int i = 0; i < res.size(); ++i) {
            if(res[i].size() == k) {
                ans.push_back(res[i]);
            }
        }
        
        return ans;
    }
};