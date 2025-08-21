/**
 * The function `minCost` calculates the minimum cost required to connect all ropes together based on
 * their lengths.
 * 
 * @param arr arr is a vector of integers representing the lengths of ropes available for combining.
 * 
 * @return The function `minCost` returns the minimum cost required to connect all the ropes in the
 * input vector `arr`.
 */
int minCost(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return 0;
    
    int sum = 0;
    while(arr.size() > 1) {
        sort(arr.begin(), arr.end());
        
        int rope1 = arr[0], rope2 = arr[1];
        arr.erase(arr.begin());
        arr.erase(arr.begin());
        
        sum += rope1 + rope2;
        arr.push_back(rope1 + rope2);
    }
    
    return sum;
}