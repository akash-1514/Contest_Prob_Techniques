class Solution {
public:
    int dp[71][5000];
    int helper(vector<vector<int>>&mat, int row, int target, int sum) {
        int n = mat.size(), m = mat[0].size();
        if(row == n) {
            return abs(sum - target);
        }
        
        if(dp[row][sum] != -1) return dp[row][sum];
        
        int mn = 1e9;
        for(int col = 0; col < m; ++col) {
            mn = min(mn, helper(mat, row + 1, target, sum + mat[row][col]));
        }
        
        return dp[row][sum] = mn;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        
        memset(dp, -1, sizeof(dp));
        return helper(mat, 0, target, 0);
    }
};