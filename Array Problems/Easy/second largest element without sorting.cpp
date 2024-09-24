#include <iostream>
#include <vector>
using namespace std;

int print2largest(vector<int> &arr) {
    int first = -1, second = -1;
    
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if(arr[i] != first && arr[i] > second) {
            second = arr[i];
        }
    }
    
    return second;
}

int main() {
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << print2largest(arr);
}