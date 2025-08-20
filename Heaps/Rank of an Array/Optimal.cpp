/**
 * The function `arrayRankTransform` takes a vector of integers, assigns ranks to each element based on
 * their values, and returns the modified vector.
 * 
 * @param arr The given code snippet is a function that takes a vector of integers `arr` as input and
 * returns a new vector where each element is replaced by its rank in the original array. The rank of
 * an element is its position in the sorted array of distinct elements.
 * 
 * @return The function `arrayRankTransform` returns a `vector<int>` containing the ranks of the
 * elements in the input array `arr`.
 */
vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i = 0; i < n; ++i) {
        pq.push({arr[i], i});
    }

    int rank = 0, prev = INT_MAX;
    while(!pq.empty()) {
        if(pq.top().first == prev) {
            arr[pq.top().second] = rank;
        }
        else {
            rank++;
            arr[pq.top().second] = rank;
        }
        prev = pq.top().first;
        pq.pop();
    }

    return arr;
}