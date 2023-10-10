class Solution {
public:
    int dp[101][101];
    int helper(vector<vector<int>>&arr, int x, int y) {
        int n = arr.size(), m = arr[0].size();
        if(x == n - 1 && y == m - 1) return 1;
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int cnt = 0;
        if(x + 1 < n && arr[x + 1][y] == 0) {
            cnt += helper(arr, x + 1, y);
        }
        if(y + 1 < m && arr[x][y + 1] == 0) {
            cnt += helper(arr, x, y + 1);
        }
        return dp[x][y] = cnt;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        if(arr[0][0] == 1 || arr[n - 1][m - 1] == 1) return 0;
        memset(dp, -1, sizeof(dp));
        return helper(arr, 0, 0);
    }
};