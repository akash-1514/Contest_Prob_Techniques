class Solution {
public:
    vector<vector<vector<double>>>dp;
    double helper(int n, int k, int x, int y) {
        if(k == 0) return 1.0;
        
        if(dp[x][y][k] != -1.0) return dp[x][y][k];
        
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        double cnt = 0;
        
        for(int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && k > 0) {
                cnt += helper(n, k - 1, nx, ny);
            }
        }
        
        return dp[x][y][k] = cnt;
    }
    double knightProbability(int n, int k, int row, int column) {
        // memset(dp, -1, sizeof(dp));
        dp.resize(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
        double ways = helper(n, k, row, column);
        return (ways) / pow(8, k);
    }
};