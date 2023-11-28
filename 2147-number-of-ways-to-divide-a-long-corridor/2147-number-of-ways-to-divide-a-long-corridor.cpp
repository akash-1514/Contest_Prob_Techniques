class Solution {
public:
    int dp[100001][3];
    long long mod = 1e9 + 7;
    int helper(string &s, int idx, int seats) {
        if(idx >= s.size()) {
            if(seats == 2) return 1;
            return 0;
        }
        
        if(dp[idx][seats] != -1) return dp[idx][seats];
        
        int ways = 0;
        if(s[idx] == 'S') {
            ways = (ways + helper(s, idx + 1, (seats + 1) > 2 ? 1 : seats + 1)) % mod;
        } else {
            if(seats == 2) {
                ways = (ways + helper(s, idx + 1, 0)) % mod;
            }
            ways = (ways + helper(s, idx + 1, seats)) % mod;
        }
        return dp[idx][seats] = ways;
    }
    int numberOfWays(string corridor) {
        int n = corridor.size();
        memset(dp, -1, sizeof(dp));
        return helper(corridor, 0, 0);
    }
};