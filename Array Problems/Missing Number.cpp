int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n;) {
        if (nums[i] < n && nums[i] != i) {
            swap(nums[i], nums[nums[i]]);
        } else {
            i++;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] != i) {
            return i;
        }
    }

    return n;
}