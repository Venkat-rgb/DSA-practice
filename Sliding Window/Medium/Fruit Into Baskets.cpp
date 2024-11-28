int totalFruits(vector<int> &arr) {
    int n = arr.size();
    
    if(n == 1) {
        return 1;
    }
    
    int i = 0, j = 0, maxi = 0;
    unordered_map <int, int> mp;
    
    while(j < n) {
        mp[arr[j]]++;
        
        while(mp.size() > 2) {
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) {
                mp.erase(arr[i]);
            }
            i++;
        }
        
        if(mp.size() == 2) {
            maxi = max(maxi, j - i + 1);
        }
        
        j++;
    }
    
    return maxi;
}