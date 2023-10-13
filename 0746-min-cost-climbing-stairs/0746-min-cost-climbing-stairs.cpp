class Solution {
public:
    int dp[1001];
    int helper(vector<int>&cost, int idx) {
        if(idx >= cost.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int mn = 1e9;
        mn = min(mn, cost[idx] + helper(cost, idx + 1));
        mn = min(mn, cost[idx] + helper(cost, idx + 2));
        return dp[idx] = mn;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        int val1 = helper(cost, 0);
        int val2 = helper(cost, 1);
        
        return min(val1, val2);
    }
};