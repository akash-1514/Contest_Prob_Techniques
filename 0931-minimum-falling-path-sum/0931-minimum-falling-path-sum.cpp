class Solution {
public:
    // int dp[101][101];
//     vector<vector<int>>dp;
//     int helper(vector<vector<int>>&arr, int x, int y) {
//         if(x == arr.size() - 1) {
//             return arr[x][y];
//         }
        
//         if(dp[x][y] != -1) return dp[x][y];
        
//         int mn = 1e9;
//         mn = min(mn, arr[x][y] + helper(arr, x + 1, y));
//         if(y + 1 < arr[0].size()) {
//             mn = min(mn, arr[x][y] + helper(arr, x + 1, y + 1));
//         }
//         if(y - 1 >= 0) {
//             mn = min(mn, arr[x][y] + helper(arr, x + 1, y - 1));
//         }
//         return dp[x][y] = mn;
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // memset(dp, -1, sizeof(dp));
        int n = matrix.size(), m = matrix[0].size();
        // dp.resize(n, vector<int>(m, -1));
        // int mn = 1e9;
        // for(int i = 0; i < matrix[0].size(); ++i) {
        //     mn = min(mn, helper(matrix, 0, i));
        // }
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int j = 0; j < m; ++j) {
            dp[n - 1][j] = matrix[n - 1][j];
        }
        
        for(int i = n - 2; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                int mn = 1e9;
                mn = min(mn, matrix[i][j] + dp[i + 1][j]);
                if(j - 1 >= 0) {
                    mn = min(mn, matrix[i][j] + dp[i + 1][j - 1]);
                }
                if(j + 1 < m) {
                    mn = min(mn, matrix[i][j] + dp[i + 1][j + 1]);
                }
                dp[i][j] = mn;
            }
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        
        int mn = 1e9;
        for(int j = 0; j < m; ++j) {
            mn = min(mn, dp[0][j]);
        }
        return mn;
    }
};