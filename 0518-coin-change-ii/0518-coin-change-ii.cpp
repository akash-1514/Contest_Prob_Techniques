class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>&coins, int idx, int amount) {
        if(idx >= coins.size()) {
            return amount == 0;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];
        
        int cnt = 0;
        if(coins[idx] <= amount) {
            cnt += helper(coins, idx, amount - coins[idx]);
        }
        cnt += helper(coins, idx + 1, amount);
        return dp[idx][amount] = cnt;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n, vector<int>(amount + 1, -1));
        return helper(coins, 0, amount);
    }
};