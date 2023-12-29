class Solution {
public:
    int dp[301][11];
    int helper(vector<int>&arr, int idx, int d) {
        if(idx >= arr.size()) {
            if(d == 0) return 0;
            return 1e9;
        }
        
        if(d < 0) return 1e9;
        
        if(dp[idx][d] != -1) return dp[idx][d];
        
        int ans = 1e9, mx = 0;
        for(int k = idx; k < arr.size(); ++k) {
            mx = max(mx, arr[k]);
            ans = min(ans, mx + helper(arr, k + 1, d - 1));
        }
        return dp[idx][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof(dp));
        int res = helper(jobDifficulty, 0, d);
        return res == 1e9 ? -1 : res;
    }
};