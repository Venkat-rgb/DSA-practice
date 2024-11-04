#include <climits>
#include <algorithm>

int check(vector <int> stalls, int mid, int k) {
    int cnt = 1, idx = 0;

    for(int i = 1; i < stalls.size(); ++i) {
        if(stalls[i] - stalls[idx] >= mid) {
            cnt++;
            idx = i;
        }
    }

    return cnt >= k;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());

    int n = stalls.size();

    int start = 1, end = stalls[n - 1] - stalls[0], ans = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;

        if(check(stalls, mid, k) == 1) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}