vector <int> prevSmaller(vector<int> &A) {
    int n = A.size();
    vector <int> res;
    stack <int> st;
    
    for(int i = 0; i < n; ++i) {
        while(!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        res.push_back(st.empty() ? -1 : st.top());
        st.push(A[i]);
    }
    
    return res;
}