#define ppi pair<int, pair<int, int>>
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        int level = 0, ans = 0;
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            int currHeight = tp.first, x = tp.second.first, y = tp.second.second;
            level = max(level, currHeight);
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                    pq.push({heightMap[nx][ny], {nx, ny}});
                    vis[nx][ny] = 1;
                    
                    if(heightMap[nx][ny] < level) {
                        ans += (level - heightMap[nx][ny]);
                    }
                }
            }
        }
        return ans;
    }
};