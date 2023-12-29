class Solution {
public:
    int dp[301][11];
    int helper(vector<int>&arr, int idx, int d) {
        if(d == 1) {
            int mx = 0;
            for(int i = idx; i < arr.size(); ++i) mx = max(mx, arr[i]);
            return mx;
        }
        
        if(dp[idx][d] != -1) return dp[idx][d];
        
        int ans = 1e9, mx = 0;
        for(int k = idx; k < arr.size() - d + 1; ++k) {
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