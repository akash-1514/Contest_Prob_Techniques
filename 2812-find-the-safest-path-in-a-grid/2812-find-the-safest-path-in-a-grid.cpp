class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        queue<pair<int, pair<int, int>>>q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    grid[i][j] = -1;
                    q.push({0, {i, j}});
                }
            }
        }
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int d = front.first, x = front.second.first, y = front.second.second;
            
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0) {
                    grid[nx][ny] = d + 1;
                    q.push({d + 1, {nx, ny}});
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == -1) grid[i][j] = 0;
            }
        }
        
        vector<vector<int>>ans(n, vector<int>(m, 0));
        
        ans[0][0] = grid[0][0];
        
        priority_queue<pair<int, pair<int, int>>>pq;
        
        pq.push({ans[0][0], {0, 0}});
        
        while(!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            int d = tp.first, x = tp.second.first, y = tp.second.second;
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int mn = min(grid[nx][ny], d);
                    if(mn > ans[nx][ny]) {
                        ans[nx][ny] = mn;
                        pq.push({mn, {nx, ny}});
                    }
                }
            }
        }
        
        return ans[n - 1][m - 1];
    }
};