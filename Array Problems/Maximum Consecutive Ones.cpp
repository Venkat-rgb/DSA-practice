int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt = 0, maxi = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            cnt++;
        } else {
            if (cnt > maxi) {
                maxi = cnt;
            }
            cnt = 0;
        }
    }

    // This condition helps in checking the last consecutive 1's if we don't
    // see 0 at end part of array
    if (cnt > maxi) {
        maxi = cnt;
    }

    return maxi;
}