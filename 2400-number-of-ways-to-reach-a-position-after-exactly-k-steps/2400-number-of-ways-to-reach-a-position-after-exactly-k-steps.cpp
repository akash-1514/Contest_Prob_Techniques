class Solution {
public:
    int mod = 1e9 + 7;
    long long expo(unsigned long long int x, int y, int p) {
        long long res = 1;
        x = x % p;

        while(y > 0) {
            if(y & 1) 
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
    long long inverse(long long n) {
        long long ans = expo(n, mod - 2, mod);
        return ans ;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int extra = k - abs(endPos - startPos);
        if(extra % 2 != 0 || abs(endPos - startPos) > k) return 0;
        int r = 1;
        for(int i = 0; i <= k; ++i) {
            if(startPos + i - (k - i) == endPos) {
                r = i;
                break;
            }
        }
        
        long long fact[k + 1];
        fact[0] = 1;
        for(int i = 1; i <= k; i++ ) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        int ans = fact[k] * inverse(fact[r]) % mod;
        ans = ans * inverse(fact[k - r]) % mod;
        ans = ans % mod;
        return ans;
    }
};