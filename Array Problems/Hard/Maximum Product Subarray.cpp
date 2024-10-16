int maxProduct(vector<int>& nums) {
    int n = nums.size();

    int maxi = INT_MIN, pref = 1, suff = 1;
    
    for(int i = 0; i < n; ++i) {
        pref *= nums[i];
        maxi = max(maxi, pref);

        if(pref == 0) {
            pref = 1;
        }
    }

    for(int i = n - 1; i >= 0; --i) {
        suff *= nums[i];
        maxi = max(maxi, suff);

        if(suff == 0) {
            suff = 1;
        }
    }

    return maxi;
}