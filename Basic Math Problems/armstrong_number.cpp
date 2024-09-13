#include <bits/stdc++.h>
using namespace std;

bool checkArmstrong(int n){
	int res = n, cnt = (int)(log10(n) + 1);
	long long sum = 0;

	while(res > 0) {
		int rem = res % 10;
		sum += pow(rem, cnt);
		res /= 10;
	}

	return sum == n;
}

int main() {
    int n;
    cin >> n;
    cout << (checkArmstrong(n) ? "true" : "false") << endl;
}