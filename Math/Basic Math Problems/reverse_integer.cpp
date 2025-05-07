#include <iostream>
#include <climits>
using namespace std;

int reverse(int x) {
    int res = 0, num = abs(x);

    while(num > 0) {
        int rem = num % 10;
        int firstResDigit = res / 100000000;
        if(firstResDigit > 2 || res > (INT_MAX / 10)) {
            return 0;
        }
        res = (res * 10) + rem;
        num /= 10;
    }

    int finalRes = x < 0 ? -res : res;

    return finalRes;     
}

int main() {
    int n;
    cin >> n;
    cout << reverse(n) << endl;
}