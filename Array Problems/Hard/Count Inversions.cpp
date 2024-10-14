long long int merge(vector <long long> &arr, int start, int mid, int end) {
    vector <long long> res;
    
    int i = start, j = mid + 1;
    long long cnt = 0;
    
    while(i <= mid && j <= end) {
        if(arr[i] > arr[j]) {
            res.push_back(arr[j]);
            cnt += (mid - i + 1);
            j++;
        }
        else {
            res.push_back(arr[i]);
            i++;
        }
    }
    
    while(i <= mid) {
        res.push_back(arr[i]);
        i++;
    }
    
    while(j <= end) {
        res.push_back(arr[j]);
        j++;
    }
    
    for(int i = 0; i < res.size(); ++i) {
        arr[i + start] = res[i];
    }
    
    return cnt;
}

long long int mergeSort(vector <long long> &arr, int start, int end) {
    // Base case
    if(start >= end) {
        return 0;
    }
    
    // Recursion work
    long long cnt = 0;
    int mid = start + (end - start) / 2;
    cnt += mergeSort(arr, start, mid);
    cnt += mergeSort(arr, mid + 1, end);
    
    // My work
    cnt += merge(arr, start, mid, end);
    
    return cnt;
}

long long int inversionCount(vector<long long> &arr) {
    long long int ans = mergeSort(arr, 0, arr.size() - 1);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector <long long> arr(n);

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long res = inversionCount(arr);

    cout << res << endl;

    return 0;
}