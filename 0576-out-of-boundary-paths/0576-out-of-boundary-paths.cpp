class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dp[52][52][51];
    const int mod = 1e9 + 7;
    int helper(int x, int y, int m, int n, int maxMove) {
        if(x > m || x == 0 || y > n || y == 0) return 1;
        
        if(dp[x][y][maxMove] != -1) return dp[x][y][maxMove];
        
        int ans = 0;
        if(maxMove > 0) {
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                ans = (ans + helper(nx, ny, m, n, maxMove - 1)) % mod;
            }
        } 
        return dp[x][y][maxMove] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return helper(startRow + 1, startColumn + 1, m, n, maxMove);
    }
};