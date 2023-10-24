class Solution {
public:
    int dp[501][501];
    int helper(vector<int>&time, vector<int> &cost, int idx, int extraTime) {
        int n = cost.size();
        if(extraTime == n) {
            return 0;
        }
        
        if(idx >= n) {
            return 1e9;    
        }
        
        if(dp[idx][extraTime] != -1) return dp[idx][extraTime];
        
        int takePaidPainter = cost[idx] + helper(time, cost, idx + 1, min(n, extraTime + time[idx] + 1));
        
        int notTakePaidPainter = helper(time, cost, idx + 1, extraTime);
        
        return dp[idx][extraTime] = min(takePaidPainter, notTakePaidPainter);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));
        return helper(time, cost, 0, 0);
    }
};