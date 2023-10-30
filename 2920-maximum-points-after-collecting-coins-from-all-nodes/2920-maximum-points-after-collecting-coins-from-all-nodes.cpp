class Solution {
public:
    int dp[100001][15];
    int helper(vector<int> graph[], int src, int par, vector<int>&coins, int k, int steps) {
        
        if(steps > 14) return 0;
        
        if(dp[src][steps] != -1) return dp[src][steps];
        
        int way1 = (coins[src] / (1 << steps)) - k;
        for(auto &adj : graph[src]) {
            if(adj != par) {
                way1 += helper(graph, adj, src, coins, k, steps);
            }
        }
        
        int way2 = (coins[src] / (1 << steps)) / 2;
        for(auto &adj : graph[src]) {
            if(adj != par) {
                way2 += helper(graph, adj, src, coins, k, steps + 1);
            }
        }
        
        return dp[src][steps] = max(way1, way2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        memset(dp, -1, sizeof(dp));
        int n = edges.size();
        vector<int> graph[n + 1];
        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return helper(graph, 0, -1, coins, k, 0);
    }
};