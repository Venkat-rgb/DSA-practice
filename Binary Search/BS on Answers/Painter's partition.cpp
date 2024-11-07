#include <climits>

int check(vector <int>& boards, int mid, int k) {
    int time_remaining = mid, painters_spawned = 1;

    for(int i = 0; i < boards.size(); ++i) {
        if(time_remaining >= boards[i]) {
            time_remaining -= boards[i];
        }
        else {
            painters_spawned++;
            if(painters_spawned > k) {
                return 0;
            }
            time_remaining = mid;
            if(time_remaining >= boards[i]) {
                time_remaining -= boards[i];
            }
            else {
                return 0;
            }
        }
    }

    return painters_spawned <= k;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int n = boards.size(), mini = INT_MAX, sum = 0;
    
    if(k > n) {
        return -1;
    }

    for(int i = 0; i < n; ++i) {
        mini = min(mini, boards[i]);
        sum += boards[i];
    }

    int start = mini, end = sum, ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if(check(boards, mid, k) == 1) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    return ans;
}