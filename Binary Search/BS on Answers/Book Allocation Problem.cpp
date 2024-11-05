int check(vector <int> arr, long long mid, int m) {
    int allocated_students = 1;
    long long pages_left = mid;
    
    for(int i = 0; i < arr.size(); ++i) {
        if(pages_left >= arr[i]) {
            pages_left -= arr[i];
        }
        else {
            allocated_students++;
            
            if(allocated_students > m) {
                return 0;
            } 
            
            pages_left = mid;
            
            if(pages_left >= arr[i]) {
                pages_left -= arr[i];
            }
            else {
                return 0;
            }
        }
    }

    return allocated_students <= m;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n) {
        return -1;
    }

    long long sum = 0;
    int mini = INT_MAX;

    for(int i = 0; i < n; ++i) {
        mini = min(mini, arr[i]);
        sum += arr[i];
    }

    long long start = mini, end = sum, ans = -1;
    while(start <= end) {
        long long mid = start + (end - start) / 2;
        if(check(arr, mid, m) == 1) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    } 

    return ans;
}