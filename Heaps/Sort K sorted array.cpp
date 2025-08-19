/* The `Solution` class in C++ provides a method `nearlySorted` that sorts a nearly sorted array with a
maximum displacement of `k` elements using a priority queue. */
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        int n = arr.size();
        if(k == 0) return;
        
        priority_queue <int, vector<int>, greater<int>> pq;
        
        int idx = 0;
        
        for(int i = 0; i < n; ++i) {
            pq.push(arr[i]);
            
            if(pq.size() > k) {
                arr[idx++] = pq.top();
                pq.pop();
            }
        }
        
        while(!pq.empty()) {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};