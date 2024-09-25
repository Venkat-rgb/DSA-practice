int majorityElement(vector<int>& nums) {
    int freq = 0, res = 0;

    for(int i = 0; i < nums.size(); ++i) {
        if(freq == 0) {
            freq = 1;
            res = nums[i];
        }
        else if(res == nums[i]) {
            freq++;
        }
        else {
            freq--;
        }
    }

    return res;
}