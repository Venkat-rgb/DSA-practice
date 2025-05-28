// Time complexity: O(sqrt(N))
// Space complexity: O(no of primes)
vector<int> AllPrimeFactors(int N) {
    vector <int> res;
    
    for(int i = 2; i * i <= N; ++i) {
        if(N % i == 0) {
            res.push_back(i);
            while(N % i == 0) {
                N = N / i;
            }
        }
    }
    
    if(N != 1) res.push_back(N);
    return res;
}