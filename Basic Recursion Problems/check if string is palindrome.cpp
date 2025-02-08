#include <iostream>
#include <string>
using namespace std;
// Time complexity: O(2N) (N for converting to lower case, N for recursion)

bool checkPalindrome(string s, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (s[start] != s[end]) {
        return false;
    }

    return checkPalindrome(s, start + 1, end - 1);
}

bool isPalindrome(string s) {
    string res = "";
    for (int i = 0; i < s.size(); ++i) {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) ||
            (s[i] >= '0' && s[i] <= '9')) {
            res += tolower(s[i]);
        }
    }

    if (res.size() == 0)
        return true;

    return checkPalindrome(res, 0, res.size() - 1);
}

int main() {
    string s;
    cin >> s;

    cout << (isPalindrome(s) ? "true" : "false") << endl;
}