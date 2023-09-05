class Solution {
public:
    int dp[1001][1001];
    int helper(vector<pair<int, int>> graph[], vector<int>&passingFee, int src, int maxTime) {
        if(src == passingFee.size() - 1) {
            return passingFee[src];
        }
        
        if(dp[src][maxTime] != -1) return dp[src][maxTime];
        
        int mn = 1e9;
        
        for(auto &adj : graph[src]) {
            int node = adj.first, t = adj.second;
            if(t <= maxTime) {
                mn = min(mn, passingFee[src] + helper(graph, passingFee, node, maxTime - t));
            }
        }
        
        return dp[src][maxTime] = mn;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<pair<int, int>>graph[n];
        for(auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }
        memset(dp, -1, sizeof(dp));
        int res = helper(graph, passingFees, 0, maxTime);
        return res == 1e9 ? -1 : res;
    }
};