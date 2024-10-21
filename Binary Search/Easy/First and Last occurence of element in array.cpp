int lowerCheck(vector <int> &nums, long long mid, int target) {
    if(nums[mid] >= target) {
        return 1;
    } 
    return 0;
}

int upperCheck(vector <int> &nums, long long mid, int target) {
    if(nums[mid] > target) {
        return 1;
    } 
    return 0;
}

int lowerBound(vector <int> &nums, int target) {
    int n = nums.size();
    int start = 0, end = n - 1, ans = n;

    while(start <= end) {
        long long mid = start + (end - start) / 2;
        if(lowerCheck(nums, mid, target) == 1) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans;
}

int upperBound(vector <int> &nums, int target) {
    int n = nums.size();
    int start = 0, end = n - 1, ans = n;

    while(start <= end) {
        long long mid = start + (end - start) / 2;
        if(upperCheck(nums, mid, target) == 1) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();

    if(n == 0) {
        return {-1, -1};
    }

    int first = lowerBound(nums, target);

    // Avoiding overflow, by checking if first == n (or) first != target
    if(first == n || nums[first] != target) {
        return {-1, -1};
    }

    // This means first exists in range (0, n - 1)
    // So even if first == 0 || first == n - 1, then last will be > first
    // So we can just do last - 1 to get last occurence
    int last = upperBound(nums, target);

    return {first, last - 1};
}