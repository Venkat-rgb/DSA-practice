vector <int> generateNthRow(int n) {
    vector <int> ans;
    
    long long prod = 1;

    ans.push_back(1);

    for(int i = 1; i < n; ++i) {
        prod = prod * (n - i);
        prod = prod / i;
        ans.push_back(prod);
    }

    return ans;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;

    for(int i = 1; i <= numRows; ++i) {
        vector <int> temp = generateNthRow(i);
        res.push_back(temp);
    }

    return res;
}