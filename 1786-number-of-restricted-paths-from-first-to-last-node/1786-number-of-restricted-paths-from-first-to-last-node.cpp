class Solution {
public:
    int mod = 1e9 + 7;
    int dfs(int n, vector<pair<int, int>> graph[], int src, vector<int>&dist, vector<int>&dp) {
        if(src == n) {
            return 1;
        }
        
        if(dp[src] != -1) return dp[src];
        
        int ans = 0;
        for(auto &adj : graph[src]) {
            int adjNode = adj.first, edgeLen = adj.second;
            if(dist[adjNode] < dist[src]) {
                ans = (ans + dfs(n, graph, adjNode, dist, dp)) % mod;
            }
        }
        return dp[src] = ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int, int>> graph[n + 1];
        for(auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        pq.push({0, n});
        dist[n] = 0;
        
        while(!pq.empty()) {
            auto front = pq.top(); 
            pq.pop();
            
            int node = front.second, distance = front.first;
            
            if(dist[node] < distance) continue;
            
            for(auto &adj : graph[node]) {
                int adjNode = adj.first, d = adj.second;
                if(dist[adjNode] > d + distance) {
                    dist[adjNode] = d + distance;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        vector<int> dp(n + 1, -1);
        return dfs(n, graph, 1, dist, dp);
    }
};