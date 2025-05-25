// Time complexity: O(N + Nlog(logN))
// Space complexity: O(no of prime factors)
vector<int> leastPrimeFactor(int n) {
    vector <int> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i = 2; i <= n; ++i) {
        arr[i] = i;
    }
    
    
    for(int i = 2; i * i <= n; ++i) {
        if(arr[i] == i) {
            for(int j = i * i; j <= n; j += i) {
                if(arr[j] == j) {
                    arr[j] = i;
                }
            }
        }
    }
    
    return arr;
}