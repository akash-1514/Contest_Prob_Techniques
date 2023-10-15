class Solution {
public:
    // vector<vector<int>>dp;
    map<pair<int, int>, int>dp;
    int mod = 1e9 + 7;
    int helper(int n, int steps, int idx) {
        if(steps == 0) {
            return (idx == 0);
        }

        // if(dp[idx][steps] != -1) return dp[idx][steps];
        if(dp.find({idx, steps}) != dp.end()) return dp[{idx, steps}];
        
        int ans = 0;
        if(idx + 1 < n) {
            ans = (ans + helper(n, steps - 1, idx + 1)) % mod;
        }
        if(idx - 1 >= 0) {
            ans = (ans + helper(n, steps - 1, idx - 1)) % mod;
        }
        ans = (ans + helper(n, steps - 1, idx)) % mod;
        return dp[{idx, steps}] = ans;
    }
    int numWays(int steps, int arrLen) {
        return helper(arrLen, steps, 0);
    }
};