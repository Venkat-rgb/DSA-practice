int check(vector <int> nums, int mid, int target) {
    if(nums[mid] >= target) {
        return 1;
    }

    return 0;
}

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int start = 0, end = n - 1, ans = n;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(check(nums, mid, target) == 1) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans;
}