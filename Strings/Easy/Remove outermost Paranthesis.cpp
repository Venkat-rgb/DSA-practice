class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string res = "";

        if(n <= 1) {
            return res;
        }

        int cnt = 0;

        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                if(cnt > 0) {
                    res += s[i];
                }
                cnt++;
            }
            else if(s[i] == ')') {
                if(cnt > 1) {
                    res += s[i];
                }
                cnt--;
            }
        }

        return res;
    }
};