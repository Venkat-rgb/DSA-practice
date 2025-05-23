class StockSpanner {
    stack <pair<int, int>> st;
    int idx;

public:
    StockSpanner() {
        idx = 0;    
    }
    
    int next(int price) {
        while(!st.empty() && st.top().second <= price) {
            st.pop();
        }

        int ans;

        if(!st.empty()) {
            ans = idx - st.top().first;
        }
        else {
            ans = idx + 1;
        }

        st.push({idx, price});
        idx++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */