#include <iostream>
using namespace std;

int evenlyDivides(int N){
    int res = N, cnt = 0;
    while(res > 0) {
        int rem = res % 10;
        if(rem == 0) {
            res /= 10;
            continue;
        } 
        if(N % rem == 0) {
            cnt++;
        }
        res /= 10;
    }
    
    return cnt;
}

int main() {
    int n;
    cin >> n;
    cout << evenlyDivides(n) << endl;
}