class Solution {
public:
    int dp[50001][2];
    int helper(vector<int>&arr, int idx, int buy, int fee) {
        if(idx >= arr.size()) {
            return 0;
        }
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy) {
            return dp[idx][buy] = max(-arr[idx] + helper(arr, idx + 1, !buy, fee), helper(arr, idx + 1, buy, fee));
        } else {
            return dp[idx][buy] = max(arr[idx] - fee + helper(arr, idx + 1, !buy, fee), helper(arr, idx + 1, buy, fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return helper(prices, 0, 1, fee);
    }
};