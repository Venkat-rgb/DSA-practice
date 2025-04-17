#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int res = (n & (n - 1));
    cout << (res == 0 ? "power of 2" : "not power of 2") << endl;
}