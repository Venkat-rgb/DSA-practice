// Time complexity: O(2^N)
void helper(vector <int> &nums, int start, vector <int> temp, vector<vector<int>> &res) {
    // 1) Base case
    if(start == nums.size()) {
        res.push_back(temp);
        return;
    }

    // 2) Recursion work + My work
    helper(nums, start + 1, temp, res);
    temp.push_back(nums[start]);
    helper(nums, start + 1, temp, res);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector <vector<int>> res;
    vector <int> temp;
    helper(nums, 0, temp, res);

    set <vector<int>> st(res.begin(), res.end());

    res.clear();

    for(auto it : st) {
        res.push_back(it);
    }

    return res;
}