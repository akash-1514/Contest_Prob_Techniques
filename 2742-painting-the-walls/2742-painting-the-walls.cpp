class Solution {
public:
    int dp[501][501];
    int helper(vector<int>&cost, vector<int>&time, int idx, int n) {
        if(n <= 0) return 0;
        if(idx >= cost.size()) return 1e9;

        if(dp[idx][n] != -1) return dp[idx][n];

        int mn = 1e9;
        mn = min(mn, cost[idx] + helper(cost, time, idx + 1, n - time[idx] - 1));
        mn = min(mn, helper(cost, time, idx + 1, n));
        return dp[idx][n] = mn;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return helper(cost, time, 0, n);
    }
};