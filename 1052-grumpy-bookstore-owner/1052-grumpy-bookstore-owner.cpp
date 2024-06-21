class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int ans = 0, n = c.size();
        for(int i = 0; i < n; ++i) {
            if(g[i] == 0) ans += c[i];
        }
        
        int mx = 0, sum = 0;
        for(int i = 0; i < m; ++i) {
            if(g[i] == 1) {
                sum += c[i];
            }
        }
        
        mx = max(mx, sum);
        
        for(int i = m; i < n; ++i) {
            if(g[i - m] == 1) sum -= c[i - m];
            if(g[i] == 1) sum += c[i];
            mx = max(mx, sum);
        }
        return ans + mx;
    }
};