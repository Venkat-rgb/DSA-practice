class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, start = 0, end = 0;

        reverse(s.begin(), s.end());

        while(i < n) {
            while(i < n && s[i] == ' ') {
                i++;
            }
            while(i < n && s[i] != ' ') {
                s[end++] = s[i++];
            }

            if(start < end) {
                reverse(s.begin() + start, s.begin() + end);
                s[end++] = ' ';
                start = end;
            }

            i++;
        }

        if(end > 0) {
            s.resize(end - 1);
        }
        return s;
    }
};