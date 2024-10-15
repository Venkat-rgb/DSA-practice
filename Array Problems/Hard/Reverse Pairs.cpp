void merge(vector <int> &nums, int start, int mid, int end) {
    vector <int> res;

    int i = start, j = mid + 1;

    while(i <= mid && j <= end) {
        if(nums[i] > nums[j]) {
            res.push_back(nums[j]);
            j++;
        }
        else {
            res.push_back(nums[i]);
            i++;
        }
    }

    while(i <= mid) {
        res.push_back(nums[i]);
        i++;
    }

    while(j <= end) {
        res.push_back(nums[j]);
        j++;
    }

    for(int i = 0; i < res.size(); ++i) {
        nums[i + start] = res[i];
    }
}

int countPairs(vector <int>& nums, int start, int mid, int end) {
    int i = start, j = mid + 1, cnt = 0;

    while(i <= mid && j <= end) {
        if(nums[i] > (long long)2 * nums[j]) {
            cnt += (mid - i + 1);
            j++;
        }
        else {
            i++;
        }
    }

    return cnt;
}

int reversePairsHelper(vector <int>& nums, int start, int end) {
    int cnt = 0;
    // Base case
    if(start >= end) {
        return cnt;
    }

    // Recursion work
    int mid = start + (end - start) / 2;

    cnt += reversePairsHelper(nums, start, mid);
    cnt += reversePairsHelper(nums, mid + 1, end);
    cnt += countPairs(nums, start, mid, end);
    
    // My work
    merge(nums, start, mid, end);

    return cnt;
}

int reversePairs(vector<int>& nums) {
    int cnt = reversePairsHelper(nums, 0, nums.size() - 1);
    return cnt;
}