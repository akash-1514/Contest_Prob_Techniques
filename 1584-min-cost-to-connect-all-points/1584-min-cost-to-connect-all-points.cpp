#define ppi pair<int, pair<int, int>>
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> graph[n];
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i].push_back({j, d});
                graph[j].push_back({i, d});
            }
        }
        
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        vector<int> vis(n, 0);
        
        pq.push({0, {0, -1}});
        
        int minCost = 0;
        while(!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            int wt = tp.first, node = tp.second.first, par = tp.second.second;
            if(vis[node]) continue;
            minCost += wt;
            vis[node] = 1;
            
            for(auto &adj : graph[node]) {
                int adjNode = adj.first, d = adj.second;
                if(!vis[adjNode]) {
                    pq.push({d, {adjNode, node}});
                }
            }
        }
        
        return minCost;
    }
};