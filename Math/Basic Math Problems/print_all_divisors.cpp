#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void printDivisors(int n){
    vector <int> res;

    // O(sqrt(n))
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            res.push_back(i);
    
            if((n / i) != i) {
                res.push_back(n / i);
            }
        }
    }

    // O((no.of.factors)log(no.of.factors)) for sorting
    sort(res.begin(), res.end());

    // O(no.of.factors)
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    // Total Time complexity: O(sqrt(n)) + O((no.of.factors)log(no.of.factors)) + O(no.of.factors)
    // Space Complexity: O(no.of.factors) for using vector to store factors.
}

int main() {
    int n;
    cin >> n;
    
    printDivisors(n); 

    return 0;
}