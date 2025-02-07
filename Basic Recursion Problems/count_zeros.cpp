#include <iostream>
using namespace std;

// Time complexity: O(log10n)
// Space complexity: O(1)
int countZeros(int n) {
    if(n <= 9){
        if(n == 0) return 1;
        else return 0;
    }

    int res = countZeros(n / 10);

    if(n % 10 == 0) {
        return res + 1;
    }
    else {
        return res;
    }
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}

// Refer to coding ninjas assignment for recursion for this problem