// Time complexity: O(min(a, b))
// Space complexity: O(1)
void gcd(int a, int b) {
    for(int i = 2; i < min(a, b); ++i) {
        if((a % i) == 0 && (b % i) == 0) {
            cout << i << " ";
        }
    }
}