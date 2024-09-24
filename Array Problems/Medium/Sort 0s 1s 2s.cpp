void sortColors(vector<int>& nums) {
    int mid = 0, start = 0, end = nums.size() - 1;

    if (nums.size() == 1) {
        return;
    }

    // If mid <= end then it means array is unsorted
    // If mid > end then it means array is sorted
    
    while (mid <= end) {
        if (nums[mid] == 0) {
            swap(nums[mid], nums[start]);
            start++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[end]);
            end--;
        }
    }
}