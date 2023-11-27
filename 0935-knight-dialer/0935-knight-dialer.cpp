class Solution {
private:
    vector<vector<char>>vec;
    int mod = 1e9 + 7;
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
public:
    int dp[5001][4][3];
    int helper(int n, int x, int y) {
        if(n == 1) {
            return 1;
        }
        
        if(dp[n][x][y] != -1) return dp[n][x][y];
        
        int cnt = 0;
        for(int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < 4 && ny < 3 && (vec[nx][ny] >= '0' && vec[nx][ny] <= '9')) {
                cnt = (cnt + helper(n - 1, nx, ny)) % mod;
            }
        }
        return dp[n][x][y] = cnt;
    }
    int knightDialer(int n) {
        int cnt = 1;
        vec.resize(4, vector<char>(3));
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(i == 3 && j == 0) vec[i][j] = '*';
                else if(i == 3 && j == 1) vec[i][j] = '0';
                else if(i == 3 && j == 2) vec[i][j] = '#';
                else {
                    vec[i][j] = (cnt + '0');
                    cnt++;
                }
            }
        }
        
        memset(dp, -1, sizeof(dp));
        
        int ans = 0;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(vec[i][j] >= '0' && vec[i][j] <= '9') {
                    ans = (ans + helper(n, i, j)) % mod;
                }
            }
        }
        return ans;
    }
};