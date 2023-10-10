class Solution {
public:
    int dp[30001][2];
    int helper(vector<int>&arr, int idx, int buy) {
        if(idx >= arr.size()) {
            return 0;
        }
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy) {
            return dp[idx][buy] = max(-arr[idx] + helper(arr, idx + 1, !buy), helper(arr, idx + 1, buy));
        } else {
            return dp[idx][buy] = max(arr[idx] + helper(arr, idx + 2, !buy), helper(arr, idx + 1, buy));
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(prices, 0, 1);
    }
};