class Solution {
public:
    int dp[100001];
    int helper(vector<vector<int>>&arr, int idx) {
        if(idx >= arr.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int mx = 0;
        vector<int>v = {arr[idx][1], INT_MAX, INT_MAX};
        auto it = upper_bound(arr.begin(), arr.end(), v) - arr.begin();
        
        mx = max(mx, arr[idx][2] + helper(arr, it));
        mx = max(mx, helper(arr, idx + 1));
        
        return dp[idx] = mx;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        memset(dp, -1, sizeof(dp));
        return helper(offers, 0);
    }
};