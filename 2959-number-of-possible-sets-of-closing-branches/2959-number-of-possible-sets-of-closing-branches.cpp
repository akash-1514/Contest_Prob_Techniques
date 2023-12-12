class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans = 0;
        for(int t = 0; t < (1 << n); ++t) {
            vector<vector<int>> dist(n, vector<int>(n, 1e9));
            for(int i = 0; i < n; ++i) dist[i][i] = 0;
            for(auto &r : roads) {
                if((t & (1 << r[0])) != 0 && (t & (1 << r[1])) != 0) {
                    dist[r[0]][r[1]] = min(dist[r[0]][r[1]], r[2]);
                    dist[r[1]][r[0]] = min(dist[r[1]][r[0]], r[2]);
                }
            }
            
            for(int k = 0; k < n; ++k) {
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < n; ++j) {
                        if(dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
            
            int mx = 0;
            for(int i = 0; i < n; ++i) {
                if((t & (1 << i)) == 0) continue;
                for(int j = 0; j < n; ++j) {
                    if((t & (1 << j)) == 0) continue;
                    mx = max(mx, dist[i][j]);
                }
            }
            
            ans += (mx <= maxDistance);
        }
        return ans;
    }
};