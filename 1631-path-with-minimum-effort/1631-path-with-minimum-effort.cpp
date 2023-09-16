#define ppi pair<int, pair<int, int>>
class Solution {
public:
    bool valid(int n, int m, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        // single source shortest path - dijstra algorithm
        vector<vector<int>>dist(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                dist[i][j] = 1e9;
            }
        }
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            
            int effort = tp.first, x = tp.second.first, y = tp.second.second;
            
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(valid(n, m, nx, ny)) {
                    int newEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                    if(dist[nx][ny] > newEffort) {
                        dist[nx][ny] = newEffort;
                        pq.push({dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};