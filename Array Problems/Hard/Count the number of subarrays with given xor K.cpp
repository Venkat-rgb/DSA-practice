#include <unordered_map>

int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size(), cnt = 0, res = 0;

    unordered_map <int, int> mp;

    for(int i = 0; i < n; ++i) {
        res ^= a[i];

        if(res == b) {
            cnt++;
        } 

        int diff = res ^ b;

        if(mp.find(diff) != mp.end()) {
            cnt += mp[diff];
        }

        mp[res]++;
    }

    return cnt;
}