class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), cnt = 0;
        int i = 0, j = 0;
        unordered_map <char, int> mp;

        while(j < n) {
            mp[s[j]] = j;

            if(mp.size() == 3) {
                int mini = min(mp['a'], min(mp['b'], mp['c']));
                cnt += (mini + 1);
            }

            j++;
        } 

        return cnt;
    }
};