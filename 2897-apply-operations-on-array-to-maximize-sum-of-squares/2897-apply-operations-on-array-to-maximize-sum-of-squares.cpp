class Solution {
public:
    int mod = 1e9 + 7;
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>bits(32, 0);
        for(int i = 0; i < n; ++i) {
            for(int k = 0; k < 32; ++k) {
                if((nums[i] & (1 << k)) != 0) {
                    bits[k]++;
                }
            }
        }
        
        int ans = 0;
        while(k--) {
            long long num = 0;
            for(int i = 31; i >= 0; --i) {
                if(bits[i] > 0) {
                    num |= (1 << i);
                    bits[i]--;
                }
            }
            ans = (ans + binpow(num, 2, mod)) % mod;
        }
        
        return ans;
    }
};