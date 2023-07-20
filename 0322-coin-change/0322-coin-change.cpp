class Solution {
public:
    int dp[13][10001];
    int helper(vector<int>&coins, int idx, int amount) {
        if(idx >= coins.size()) {
            if(amount == 0) return 0;
            return 1e9;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int mn = 1e9;
        if(coins[idx] <= amount) {
            mn = min(mn, 1 + helper(coins, idx, amount - coins[idx]));
        }
        mn = min(mn, helper(coins, idx + 1, amount));
        return dp[idx][amount] = mn;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = helper(coins, 0, amount);
        return res == 1e9 ? -1 : res;
    }
};