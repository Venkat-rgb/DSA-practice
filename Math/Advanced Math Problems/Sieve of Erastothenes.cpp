// Time complexity: O(Nlog(logN))
// Space complexity: O(no of primes)
void countPrimes(int n) {
    vector <int> arr(n, 1);

    for(int i = 2; i * i < n; ++i) {
        if(arr[i] == 1) {
            for(int j = i * i; j < n; j += i) {
                arr[j] = 0;
            } 
        }
    }

    for(int i = 2; i < n; ++i) {
        if(arr[i] == 1) {
            cout << i << " ";
        }
    }
}