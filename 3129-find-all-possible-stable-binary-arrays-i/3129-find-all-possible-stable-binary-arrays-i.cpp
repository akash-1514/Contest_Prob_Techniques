class Solution {
public:
    int z, o;
    int dp[201][201][201][2];
    int mod = 1e9 + 7;
    int helper(int zero, int one, int limit, int prev, bool fl) {
        if(zero == 0 && one == 0) {
            return 1;
        }
        
        if(dp[zero][one][prev][fl] != -1) return dp[zero][one][prev][fl];
        
        int currIdx = (z + o) - (zero + one);
        
        int ways = 0;
        if(prev == 200) {
            ways = (ways + helper(zero - 1, one, limit, limit - 1, false)) % mod;
            ways = (ways + helper(zero, one - 1, limit, limit - 1, true)) % mod;
        } else {
            if(fl) {
                if(prev > 0) {
                    if(zero > 0) {
                        ways = (ways + helper(zero - 1, one, limit, limit - 1, false)) % mod;
                    } 
                    if(one > 0) {
                        ways = (ways + helper(zero, one - 1, limit, prev - 1, true)) % mod;
                    }
                } else {
                    if(zero > 0) {
                        ways = (ways + helper(zero - 1, one, limit, limit - 1, false)) % mod;
                    } 
                }
            } else {
                if(prev > 0) {
                    if(zero > 0) {
                        ways = (ways + helper(zero - 1, one, limit, prev - 1, false)) % mod;
                    } 
                    if(one > 0) {
                        ways = (ways + helper(zero, one - 1, limit, limit - 1, true)) % mod;
                    }
                } else {
                    if(one > 0) {
                        ways = (ways + helper(zero, one - 1, limit, limit - 1, true)) % mod;
                    } 
                }
            }
        }
        
        return dp[zero][one][prev][fl] = ways;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        z = zero, o = one;
        memset(dp, -1, sizeof(dp));
        return helper(zero, one, limit, 200, false);
    }
};