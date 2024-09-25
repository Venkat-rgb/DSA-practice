vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();

    unordered_map <int, int> mp;
    vector <int> res;

    for(int i = 0; i < n; ++i) {
        int num = target - nums[i];
        if(mp.find(num) != mp.end()) {
            res.push_back(mp[num]);
            res.push_back(i);
            break;
        }
        else {
            mp[nums[i]] = i;
        }
    }

    return res;
}