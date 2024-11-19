class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        for(int i = 0; i < n; ++i) {
            mp[s[i]]++;
        }

        vector <string> bucket(n + 1, "");
        string res = "";

        for(auto it : mp) {
            int freq = it.second;
            char ch = it.first;
            bucket[freq].append(freq, ch);
        }

        for(int i = bucket.size() - 1; i >= 0; --i) {
            if(!bucket[i].empty()) {
                res += bucket[i];
            }
        }

        return res;
    }
};