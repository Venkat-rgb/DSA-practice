#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(vector<int>& C, long long mid, int A, int B) {
    long long time_left = 0, painters_spawned = 0;
    for (int i = 0; i < C.size(); ++i) {
        long long required_time = (long long)C[i] * B;
        
        if (time_left >= required_time) {
            time_left -= required_time;
        } else {
            painters_spawned++;
            if (painters_spawned > A) {
                return 0;
            }
            time_left = mid;
            if (time_left >= required_time) {
                time_left -= required_time;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

int painterPartition(int A, int B, vector<int>& C) {
    long long maxRange = 0;
    
    for (int i = 0; i < C.size(); ++i) {
        maxRange += (long long)B * C[i];  // Cast to long long to prevent overflow
    }
    
    long long start = 1, end = maxRange, ans = -1;
    
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        if (check(C, mid, A, B) == 1) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    return (int)(ans % 10000003);  // Return ans modulo 10000003, cast to int
}


int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector <int> arr(n);
    
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << painterPartition(a, b, arr);

    return 0;
}