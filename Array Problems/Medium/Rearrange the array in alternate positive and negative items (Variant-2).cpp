#include <bits/stdc++.h> 

// Time complexity: O(N) (for populating positive and negative arrays) + O(N) (for placing alternate elements inplace)
// Space complexity: O(N) (for both positive + negative combined)    

void posAndNeg(vector<int> &arr)
{
    int n = arr.size();

    vector <int> pos, neg;

    for(int i = 0; i < n; ++i) {
        if(arr[i] >= 0) {
            pos.push_back(arr[i]);
        }
        else {
            neg.push_back(arr[i]);
        }
    }

    int i = 0, idx = 0;
    while(i < pos.size() && i < neg.size()) {
        arr[idx++] = pos[i];
        arr[idx++] = neg[i];
        i++;
    }

    while(i < pos.size()) {
        arr[idx++] = pos[i];
        i++;
    }

    while(i < neg.size()) {
        arr[idx++] = neg[i];
        i++;
    }
}