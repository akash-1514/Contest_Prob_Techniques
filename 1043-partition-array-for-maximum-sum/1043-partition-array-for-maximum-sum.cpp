class Solution {
public:
    int dp[501];
    int helper(vector<int>&arr, int idx, int k) {
        if(idx >= arr.size()) {
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        int maxSum = 0, mx = 0;
        
        for(int i = idx; i < min(idx + k, (int)arr.size()); ++i) {
            mx = max(mx, arr[i]);
            maxSum = max(maxSum, mx * (i - idx + 1) + helper(arr, i + 1, k));
        }
        return dp[idx] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return helper(arr, 0, k);
    }
};