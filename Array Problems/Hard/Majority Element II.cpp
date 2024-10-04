vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    
    int freq1 = 0, freq2 = 0, curr1 = INT_MIN, curr2 = INT_MIN;

    // Find the atmost 2 majority elements 
    for(int i = 0; i < n; ++i) {
        if(freq1 == 0 && nums[i] != curr2) {
            curr1 = nums[i];
            freq1++;
        }
        else if(freq2 == 0 && nums[i] != curr1) {
            curr2 = nums[i];
            freq2++;
        }
        else if(curr1 == nums[i]) {
            freq1++;
        }
        else if(curr2 == nums[i]) {
            freq2++;
        }
        else {
            freq1--;
            freq2--;
        }
    }

    int cnt1 = 0, cnt2 = 0;

    vector <int> res;

    for(int i = 0; i < n; ++i) {
        if(curr1 == nums[i]) cnt1++;
        if(curr2 == nums[i]) cnt2++;
    }

    // If first majority element is valid
    if(cnt1 > n / 3) {
        res.push_back(curr1);
    }

    // If second majorit element is valid
    if(cnt2 > n / 3) {
        res.push_back(curr2);
    }


    // res may contain 2 (or) 1 (or) 0 majority elements
    return res;
}