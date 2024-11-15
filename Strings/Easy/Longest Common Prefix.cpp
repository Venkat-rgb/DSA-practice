class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        sort(strs.begin(), strs.end());

        string res = "", first = strs[0], last = strs[n - 1];
        
        for(int i = 0; i < first.size(); ++i) {
            if(first[i] != last[i]) {
                return res;
            }
            res += first[i];
        }

        return res;
    }
};