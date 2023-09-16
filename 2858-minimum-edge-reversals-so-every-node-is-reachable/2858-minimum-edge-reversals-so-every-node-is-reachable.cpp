class Solution {
public:
    map<pair<int, int>, int>dp;
    int dfs(vector<pair<int, int>> graph[], int src, int par) {
        if(dp.find({src, par}) != dp.end())  {
            return dp[{src, par}];
        }
        int cnt = 0;
        for(auto &adj : graph[src]) {
            if(adj.first != par) {
                cnt += (adj.second + dfs(graph, adj.first, src));
            }
        }
        return dp[{src, par}] = cnt;
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> graph[n];
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back({v, 0});
            graph[v].push_back({u, 1});
        }
        
        vector<int>ans;
        for(int i = 0; i < n; ++i) {
            int res = dfs(graph, i, -1);
            ans.push_back(res);
        }
        return ans;
    }
};