vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();

    if (n == 1) {
        return intervals;
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;

    res.push_back({intervals[0][0], intervals[0][1]});

    for(int i = 1; i < n; ++i) {
        int L1 = res.back()[0];
        int R1 = res.back()[1];
        int L2 = intervals[i][0];
        int R2 = intervals[i][1];

        if(L2 <= R1) {
            int mini = min(L1, L2);
            int maxi = max(R1, R2);

            res[res.size() - 1] = {mini, maxi};
        }   
        else {
            res.push_back({L2, R2});
        }
    }

    return res;
}