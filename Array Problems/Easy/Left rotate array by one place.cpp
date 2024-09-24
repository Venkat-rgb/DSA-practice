#include <bits/stdc++.h> 
vector<int> rotateArray(vector<int>& arr, int n) {
    int idx = 0, firstEl = arr[0];

    for(int i = 1; i < n; ++i) {
        arr[idx++] = arr[i];
    }

    arr[idx] = firstEl;

    return arr;
}
