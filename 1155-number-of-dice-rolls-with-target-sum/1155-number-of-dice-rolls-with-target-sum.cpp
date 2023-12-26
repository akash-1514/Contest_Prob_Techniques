class Solution {
public:
    int mod = 1e9 + 7;
    int dp[31][1001];
    int helper(int n, int k, int target) {
        if(n == 0) {
            return target == 0;
        }
        
        if(dp[n][target] != -1) return dp[n][target];
        
        int cnt = 0;
        for(int i = 1; i <= k; ++i) {
            if(target >= i) {
                cnt = (cnt + helper(n - 1, k, target - i)) % mod;
            } else {
                break;
            }
        }
        return dp[n][target] = cnt;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(n, k, target);
    }
};