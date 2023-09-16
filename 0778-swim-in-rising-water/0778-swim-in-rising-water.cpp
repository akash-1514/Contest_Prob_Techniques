#define ppi pair<int, pair<int, int>>
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dist[i][j] = 1e9;
            }
        }
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            
            int time = tp.first, x = tp.second.first, y = tp.second.second;
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    if(grid[nx][ny] <= time) {
                        if(time < dist[nx][ny]) {
                            dist[nx][ny] = time;
                            pq.push({time, {nx, ny}});
                        }
                    } else {
                        int newTime = time + abs(grid[nx][ny] - time);
                        if(newTime < dist[nx][ny]) {
                            dist[nx][ny] = newTime;
                            pq.push({newTime, {nx, ny}});
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        return dist[n - 1][n - 1];
    }
};