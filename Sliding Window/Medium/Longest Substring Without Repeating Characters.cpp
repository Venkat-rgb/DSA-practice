class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxi = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mp;

        while (j < n) {
            mp[s[j]]++;

            if (j - i + 1 == mp.size()) {
                maxi = max(maxi, j - i + 1);
            } else {
                while (j - i + 1 > mp.size()) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                if (j - i + 1 == mp.size()) {
                    maxi = max(maxi, j - i + 1);
                }
            }
            j++;
        }

        return maxi;
    }
};