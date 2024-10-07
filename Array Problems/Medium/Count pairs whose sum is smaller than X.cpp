int countPairs(vector<int>& nums, int target) {
    int n = nums.size(), cnt = 0;

    sort(nums.begin(), nums.end());

    int i = 0, j = n - 1;

    while(i < j) {
        int sum = nums[i] + nums[j];
        if(sum < target) {
            cnt += (j - i);
            i++;
        }
        else {
            j--;
        }
    }

    return cnt;
}