class Solution {
public:
    int dp[201][201];
    int helper(vector<vector<int>>&arr, int r, int c) {
        int n = arr.size();
        if(r == n - 1) {
            return arr[r][c];
        }
        
        if(dp[r][c] != -1) return dp[r][c];
        
        int mn = 1e9;
        mn = min(mn, arr[r][c] + helper(arr, r + 1, c));
        if(c + 1 < arr[r + 1].size()) {
            mn = min(mn, arr[r][c] + helper(arr, r + 1, c + 1));
        }
        return dp[r][c] = mn;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return helper(triangle, 0, 0);
    }
};