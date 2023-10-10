class Solution {
public:
    int dp[1001][2][101];
    int helper(vector<int>&arr, int k, int idx, int buy, int trans) {
        if(idx >= arr.size()) {
            return 0;
        }
        
        if(dp[idx][buy][trans] != -1) return dp[idx][buy][trans];
    
        int mx = 0;
        if(buy) {
            if(trans < k) {
                mx = max({mx, -arr[idx] + helper(arr, k, idx + 1, !buy, trans), helper(arr, k, idx + 1, buy, trans)});
            }
        } else {
            mx = max({mx, arr[idx] + helper(arr, k, idx + 1, !buy, trans + 1), helper(arr, k, idx + 1, buy, trans)});
        }
        
        return dp[idx][buy][trans] = mx;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return helper(prices, k, 0, 1, 0);
    }
};