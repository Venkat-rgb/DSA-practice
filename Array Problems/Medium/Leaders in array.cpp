vector<int> leaders(int n, int arr[]) {
    vector <int> res;
    
    int maxi = INT_MIN;
    
    for(int i = n - 1; i >= 0; --i) {
        if(arr[i] > maxi || arr[i] == maxi) {
            res.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}