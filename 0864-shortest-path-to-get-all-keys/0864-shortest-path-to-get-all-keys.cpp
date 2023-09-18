class Solution {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int totKeys = 0, n = grid.size(), m = grid[0].size();
        int sx, sy;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    totKeys++;
                }
                if(grid[i][j] == '@') {
                    sx = i, sy = j;
                }
            }
        }        
        string temp = to_string(sx) + "," + to_string(sy) + "," + "0";
        unordered_set<string>vis;
        vis.insert(temp);
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {sx, sy}});
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto front = q.front();
                q.pop();
                int mask = front.first, x = front.second.first, y = front.second.second;
                cout << x << " " << y << " " << mask << endl;
                if(mask == ((1 << totKeys) - 1)) {
                    return ans;
                }
                for(int i = 0; i < 4; ++i) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        if(grid[nx][ny] == '#') continue;
                        if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                            int temp = mask | (1 << (grid[nx][ny] - 'a'));
                            string check = to_string(nx) + "," + to_string(ny) + "," + to_string(temp);
                            if(vis.find(check) == vis.end()) {
                                vis.insert(check);
                                q.push({temp, {nx, ny}});
                            }
                        } else if(grid[nx][ny] == '.' || grid[nx][ny] == '@' || ((grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') && (mask & (1 << grid[nx][ny] - 'A')) != 0)) {
                            string check = to_string(nx) + "," + to_string(ny) + "," + to_string(mask);
                            if(vis.find(check) == vis.end()) {
                                vis.insert(check);
                                q.push({mask, {nx, ny}});
                            }   
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};