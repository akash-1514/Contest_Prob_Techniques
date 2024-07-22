class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            int mxx = 0;
            for(int j = 0; j < m; ++j) {
                mxx = max(mxx, mat[i][j]);
            }
            mx += mxx;
        }
        
        mx = max(mx, target);
        
        vector<vector<int>> dp(n + 1, vector<int>(mx + 1, 0));
        
        dp[n][0] = 1;
        
        for(int row = n - 1; row >= 0; --row) {
            for(int k = 0; k <= mx; ++k) {
                bool res = false;
                for(int col = 0; col < m; ++col) {
                    if(mat[row][col] <= k) {
                        res |= dp[row + 1][k - mat[row][col]];
                    }
                }
                dp[row][k] = res;
            }
        }
        
        int ans = 1e9;
        
        for(int i = 0; i <= mx; ++i) {
            if(dp[0][i]) {
                ans = min(ans, abs(i - target));
            }
        }
        
        return ans;
    }
};