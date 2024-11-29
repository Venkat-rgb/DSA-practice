class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), maxCharFreq = 0, maxLen = 0;
        int i = 0, j = 0;
        unordered_map <char, int> mp;

        while(j < n) {
            mp[s[j]]++;
            maxCharFreq = max(maxCharFreq, mp[s[j]]);

            while((j - i + 1) - maxCharFreq > k) {
                mp[s[i]]--;
                maxCharFreq = max(maxCharFreq, mp[s[j]]);
                
                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }

                i++;
            }

            if((j - i + 1) - maxCharFreq <= k) {
                maxLen = max(maxLen, j - i + 1);
            }

            j++;
        }

        return maxLen;
    }
};