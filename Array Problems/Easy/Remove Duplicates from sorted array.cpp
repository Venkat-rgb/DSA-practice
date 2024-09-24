int removeDuplicates(vector<int>& nums) {
    int uniqueCnt = 1;

    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] != nums[i - 1]) {
            nums[uniqueCnt++] = nums[i];
        }
    }

    return uniqueCnt;
}