class Solution {
    public:
        vector <int> sieve(int n) {
            vector <int> arr(n + 1, 1);
    
            for(int i = 2; i * i <= n; ++i) {
                if(arr[i] == 1) {
                    for(int j = i * i; j <= n; j += i) {
                        arr[j] = 0;
                    }
                }
            }
    
            return arr;
        }
    
        vector<vector<int>> findPrimePairs(int n) {
            vector <int> arr = sieve((int)1e6);
            vector<vector<int>> res;
    
            for(int i = 2; i <= n / 2; ++i) {
                if(arr[i] == 1 && arr[n - i] == 1) {
                    if(i + (n - i) == n) {
                        res.push_back({i, n - i});
                    }
                }
            }
            
            return res;
        }   
    };