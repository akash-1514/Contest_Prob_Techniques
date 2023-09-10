class Solution {
public:
    const int mod = 1e9 + 7;
    int countOrders(int n) {
        long long ans = 1;
        for(int i = 2; i <= n; ++i) {
            long long options = 2 * i - 1;
            long long ways = (options * (options + 1)) / 2;
            ans = (ans * 1ll * ways) % mod;
        }
        return ans;
    }
};