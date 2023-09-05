class Solution {
public:
    int ans = 0;
    void helper(vector<pair<int, int>> graph[], int src, int maxTime, int quality, vector<int>&values, vector<int>&vis) {
        quality += (vis[src] ? 0 : values[src]);
        vis[src]++;
        if(src == 0) {
            ans = max(ans, quality);
        }
        
        for(auto &adj : graph[src]) {
            if(adj.second <= maxTime) {
                helper(graph, adj.first, maxTime - adj.second, quality, values, vis);
            }
        }
        vis[src]--;
        quality -= (vis[src] ? 0 : values[src]);
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<pair<int, int>> graph[n];
        for(auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }
        
        vector<int>vis(n, 0);
        helper(graph, 0, maxTime, 0, values, vis);
        return ans;
    }
};