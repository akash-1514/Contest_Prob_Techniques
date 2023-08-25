class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>&arr, int t1, int idx) {
        if(idx >= arr.size()) {
            if(t1 == 0) return 0;
            return -1e9;
        }
        
        if(dp[t1 + 5000][idx] != -1) return dp[t1 + 5000][idx];
        
        int mx = -1e9;
        mx = max(mx, arr[idx] + helper(arr, t1 + arr[idx], idx + 1));
        mx = max(mx, helper(arr, t1 - arr[idx], idx + 1));
        mx = max(mx, helper(arr, t1, idx + 1));
        return dp[t1 + 5000][idx] = mx;
    }
    int tallestBillboard(vector<int>& rods) {
        int tot = 0;
        for(int ele : rods) tot += ele;
        dp.resize(tot + 5005, vector<int>(rods.size(), -1));
        return helper(rods, 0, 0);
    }
};