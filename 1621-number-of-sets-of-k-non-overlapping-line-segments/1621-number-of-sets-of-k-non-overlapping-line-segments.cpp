class Solution {
public:
    int numberOfSets(int n, int k) {
        long long mod = 1e9 + 7;
        long long num = 1, den = 1;
        
        for (int i = 1; i <= 2 * k; ++i) {
            num = (num * (n + k - i)) % mod;
            den = (den * i) % mod;
        }
        
        long long inv = 1, base = den, exp = mod - 2;
        while (exp > 0) {
            if (exp % 2 == 1) inv = (inv * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        
        return (num * inv) % mod;
    }
};