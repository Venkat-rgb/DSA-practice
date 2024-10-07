vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector <vector<int>> res;

    int i = 0, j = 1, k = n - 1;

    while(i < n) {
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == 0) {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                // Ignoring the Duplicates
                while(j < k && nums[j] == nums[j - 1]) {
                    j++;
                }

                // Ignoring the Duplicates
                while(j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
            else if(sum < 0) {
                j++;
            }
            else {
                k--;
            }   
        }
        i++;

        // Ignoring the Duplicates
        while(i > 0 && i < n && nums[i] == nums[i - 1]) {
            i++;
        }

        j = i + 1;
        k = n - 1;
    }
    
    return res;
}