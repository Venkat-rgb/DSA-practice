class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), cnt = 0;

        for(int i = 0; i < n; ++i) {
            unordered_map <char, int> mp;
            
            for(int j = i; j < n; ++j) {
                mp[s[j]]++;

                int mini = INT_MAX, maxi = INT_MIN;

                for(auto it : mp) {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }

                cnt += (maxi - mini);
            }
        }

        return cnt;
    }
};