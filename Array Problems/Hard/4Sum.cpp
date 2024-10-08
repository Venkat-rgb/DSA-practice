vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();

    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
        // Handling the duplicates
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < n; ++j) {
            // Handling the duplicates
            if (j - 1 != i && nums[j] == nums[j - 1]) {
                continue;
            }

            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                long long sum = (long long)nums[i] + (long long)nums[j] +
                                (long long)nums[k] + (long long)nums[l];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    // Handling the duplicates
                    while (k < l && nums[k] == nums[k - 1]) {
                        k++;
                    }

                    // Handling the duplicates
                    while (k < l && nums[l] == nums[l + 1]) {
                        l--;
                    }
                } else if (sum > target) {
                    l--;
                } else {
                    k++;
                }
            }
        }
    }

    return res;
}