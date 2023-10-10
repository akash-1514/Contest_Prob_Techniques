class Solution {
public:
    int dp[100001][2][3];
    int helper(vector<int>&arr, int idx, int buy, int trans) {
        if(idx >= arr.size()) {
            return 0;
        }
        
        if(dp[idx][buy][trans] != -1) return dp[idx][buy][trans];
    
        int mx = 0;
        if(buy) {
            if(trans < 2) {
                mx = max({mx, -arr[idx] + helper(arr, idx + 1, !buy, trans), helper(arr, idx + 1, buy, trans)});
            }
        } else {
            mx = max({mx, arr[idx] + helper(arr, idx + 1, !buy, trans + 1), helper(arr, idx + 1, buy, trans)});
        }
        
        return dp[idx][buy][trans] = mx;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(prices, 0, 1, 0);
    }
};