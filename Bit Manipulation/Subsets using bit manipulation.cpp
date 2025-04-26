vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size(), total = pow(2, n);
    vector <vector <int>> res;

    for(int i = 0; i < total; ++i) {
        vector <int> temp;

        for(int j = 0; j < n; ++j) {
            int mask = i & (1 << j);
            if(mask != 0) {
                temp.push_back(nums[j]);
            }
        }

        res.push_back(temp);
    }

    return res;
}