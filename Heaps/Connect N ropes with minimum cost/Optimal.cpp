/**
 * The function `minCost` calculates the minimum cost of combining elements in an array using a
 * priority queue.
 * 
 * @param arr An array of long long integers containing the costs of items.
 * @param n The parameter `n` in the `minCost` function represents the number of elements in the array
 * `arr[]`. It is used to determine the size of the array and iterate over its elements in the
 * function.
 * 
 * @return The function `minCost` is returning the minimum cost required to merge all elements in the
 * array `arr` into a single element.
 */
long long minCost(long long arr[], long long n) {
    priority_queue <long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < n; ++i) {
        pq.push(arr[i]);
    } 
    long long sum = 0;
    while(pq.size() >= 2) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        sum += first + second;
        pq.push(first + second);
    }
    return sum;
}