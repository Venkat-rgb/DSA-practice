//User function template for C++

class Solution
{
  public:
    long long int atMost(string s, int k) {
        int n = s.size(), i = 0, j = 0;
        long long int cnt = 0;
        unordered_map <char, int> mp;
        
        if(k < 0) {
            return 0;
        }
        
        while(j < n) {
            mp[s[j]]++;
            
            while(mp.size() > k) {
                mp[s[i]]--;
                
                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                
                i++;
            }
            
            if(mp.size() <= k) {
                cnt += j - i + 1;
            }
            
            j++;
        }
        
        return cnt;
    }
  
    long long int substrCount (string s, int k) {
    	if(k > s.size()) {
    	    return 0;
    	}
    	
    	long long int res_k = atMost(s, k);
        long long int res_k_1 = atMost(s, k - 1);
        
        return res_k - res_k_1;
    }
};