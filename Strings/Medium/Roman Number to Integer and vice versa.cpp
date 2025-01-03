// Time complexity: O(N)
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(), sum = 0;

        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        for (int i = 0; i < n; ++i) {
            if(i + 1 < n && mp[s[i]] < mp[s[i + 1]]) {
                sum -= mp[s[i]];
            }
            else {
                sum += mp[s[i]];
            }
        }

        return sum;
    }
};