class Solution{
	public:
	
	long long calcPow(int mid, int n, int m) {
	    long long res = 1;
	    
	    while(n > 0) {
	        if(res > m) {
	            return res;
	        }
	        
	        res *= mid;
	        n--;
	    }
	    
	    return res;
	}
	
	int check(int mid, int m, int n) {
	    long long res = calcPow(mid, n, m);
	    
	    if(res >= m) {
	        return 1;
	    }
	    
	    return 0;
	}
	
	int NthRoot(int n, int m)
	{
	    int start = 1, end = m, ans = -1;
	    
	    while(start <= end) {
	        int mid = start + (end - start) / 2;
	        if(check(mid, m, n) == 1) {
	            ans = mid;
	            end = mid - 1;
	        }
	        else {
	            start = mid + 1;
	        }
	    }
	    
	    return (long long)pow(ans, n) == m ? ans : -1;
	}  
};