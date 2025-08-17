/**
 * The function `findKthLargest` uses a min heap to find the kth largest element in a vector of
 * integers.
 * 
 * @param nums The `nums` parameter is a vector of integers that contains the elements from which we
 * need to find the kth largest element. The function `findKthLargest` uses a priority queue to
 * efficiently find the kth largest element in the vector.
 * @param k The parameter `k` in the `findKthLargest` function represents the position of the element
 * we want to find in the sorted order. For example, if `k` is 1, we are looking for the largest
 * element in the vector. If `k` is 2,
 * 
 * @return The function `findKthLargest` returns the kth largest element in the given vector `nums`.
 */
int findKthLargest(vector<int>& nums, int k) {
    priority_queue <int, vector<int>, greater<int>> pq;

    for(int i = 0; i < nums.size(); ++i) {
        pq.push(nums[i]);

        if(pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}