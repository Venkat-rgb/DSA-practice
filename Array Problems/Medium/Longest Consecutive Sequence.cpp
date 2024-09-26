int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }

    unordered_set <int> s;

    for(int i = 0; i < nums.size(); ++i) {
        s.insert(nums[i]);
    }

    int maxi = INT_MIN;

    for(auto it : s) {
        if(s.find(it - 1) == s.end()) {
            int res = it + 1, cnt = 1;
            while(s.find(res) != s.end()) {
                cnt++;
                res++;
            }
            maxi = max(maxi, cnt);
        }
    }

    return maxi;
}