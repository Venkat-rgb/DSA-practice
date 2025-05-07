// Time complexity: O(log10n)
// Space complexity: O(1)

#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;

    int res = 0, num = x;

    while(num > 0) {
        int rem = num % 10;
        int firstResDigit = res / 100000000;
        if(firstResDigit > 2 || res > (INT_MAX / 10)) {
            return false;
        }
        res = (res * 10) + rem;
        num /= 10;
    }

    return x == res;
}

int main() {
    int n;
    cin >> n;
    cout << (isPalindrome(n) ? "true" : "false") << endl;
}