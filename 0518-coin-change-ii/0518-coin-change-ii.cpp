class Solution {
public:
    int dp[301][5001];
    int helper(vector<int>&arr, int idx, int amount) {
        if(amount == 0) return 1;
        if(idx >= arr.size()) return 0;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int pick = 0;
        if(arr[idx] <= amount) {
            pick = helper(arr, idx, amount - arr[idx]);
        } 
        int notPick = helper(arr, idx + 1, amount);
        return dp[idx][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return helper(coins, 0, amount);
    }
};