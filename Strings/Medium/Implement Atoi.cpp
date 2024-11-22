class Solution {
public:
    int myAtoi(string s) {
        // Keeps track of the sign
        bool isNegative = false;

        int n = s.size(), start = 0, res = 0;

        // Ignoring leading spaces
        while (start < n && s[start] == ' ') {
            start++;
        }

        // Deciding sign
        if (start < n && s[start] == '-') {
            isNegative = true;
            start++;
        } else if (start < n && s[start] == '+') {
            start++;
        }

        // Removing leading zeros
        while (start < n && s[start] == '0') {
            start++;
        }

        for (int i = start; i < n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = s[i] - '0';

                // Rounding of negative number
                if (isNegative) {
                    if (-res == INT_MIN || -res < INT_MIN / 10 ||
                        (-res == INT_MIN / 10 && num >= 8)) {
                        return INT_MIN;
                    }
                }

                // Rounding of positive number
                else {
                    if (res == INT_MAX || res > INT_MAX / 10 ||
                        (res == INT_MAX / 10 && num >= 7)) {
                        return INT_MAX;
                    }
                }

                // Adding number to result
                res = (res * 10) + (s[i] - '0');
            } else {
                // Returning number as we found character in middle of string
                return isNegative ? -res : res;
            }
        }

        return isNegative ? -res : res;
    }
};