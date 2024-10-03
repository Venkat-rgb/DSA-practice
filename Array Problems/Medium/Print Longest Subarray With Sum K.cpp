void printLongestSubarrayWithSumK(vector <int> arr, int k) {
    int start = 0, end = 0, sum = 0;
    
    unordered_map <int, int> mp;
    
    for(int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        
        if(sum == k) {
            end = i;
        }
        
        if(mp.find(sum - k) != mp.end()) {
            start = mp[sum - k] + 1;
            end = i;
        }
        
        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    
    for(int i = start; i <= end; ++i) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int k;
    cin >> k;
    
    printLongestSubarrayWithSumK(arr, k);
}