class Solution {
public:
    bool valid(int n, int m, int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, pair<int, int>>>q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(mat[i][j] == 0) {
                    q.push({0, {i, j}});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            int d = front.first, x = front.second.first, y = front.second.second;
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(valid(n, m, nx, ny) && mat[nx][ny] == -1) {
                    mat[nx][ny] = d + 1;
                    q.push({d + 1, {nx, ny}});
                }
            }
        }
        return mat;
    }
};