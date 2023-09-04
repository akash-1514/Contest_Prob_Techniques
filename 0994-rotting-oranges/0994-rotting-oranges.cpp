class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totOranges = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>>q;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    totOranges++;
                } else if(grid[i][j] == 1) {
                    totOranges++;
                }
            }
        }
        
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        int cnt = 0;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.second.first, y = front.second.second, time = front.first;
            if(++cnt == totOranges) {
                return time;
            }
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({time + 1, {nx, ny}});
                }
            }
        }
        
        return cnt == totOranges ? 0 : -1;
    }
};