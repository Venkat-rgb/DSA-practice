int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0, maxi = INT_MIN, cnt = 0;
    unordered_map <int, int> mp;

    for(int i = 0; i < n; ++i) {
        sum += nums[i];

        if(sum == k) {
            cnt++;
        }

        int diff = sum - k;

        if(mp.find(diff) != mp.end()) {
            cnt += mp[diff];
        }
        
        mp[sum]++;
    }

    return cnt;
}