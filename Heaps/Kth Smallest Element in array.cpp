/**
 * The function `findKthSmallest` uses a priority queue to find the kth smallest element in a given
 * vector of integers.
 * 
 * @param nums The `nums` parameter is a vector of integers that contains the elements from which we
 * need to find the kth smallest element.
 * @param k K is the integer representing the kth smallest element to be found in the vector nums.
 * 
 * @return The function `findKthSmallest` returns the kth smallest element in the given vector `nums`.
 */
int findKthSmallest(vector<int>& nums, int k) {
    priority_queue <int> pq;

    for(int i = 0; i < nums.size(); ++i) {
        pq.push(nums[i]);

        if(pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}