// Time complexity: O(2^N)
// Space complexity: O(N)

class Solution {
public:
    vector<vector<int>> helper(vector<int>& arr, int start) {
        // 1) Base case
        if(start == arr.size()) {
            return {{}};
        }

        // 2) Recursion work
        vector <vector<int>> res = helper(arr, start + 1);

        // 3) My work
        int size = res.size();

        for(int i = 0; i < size; ++i) {
            vector <int> temp;
            temp.push_back(arr[start]);

            for(int j = 0; j < res[i].size(); ++j) {
                temp.push_back(res[i][j]);
            }

            res.push_back(temp);
        }

        return res;
    }

    vector<vector<int>> subsets(vector<int>& nums) { return helper(nums, 0); }
};