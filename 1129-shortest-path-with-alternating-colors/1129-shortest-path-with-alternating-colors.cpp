class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> graph[n];
        for(auto &e : redEdges) graph[e[0]].push_back({e[1], 1});
        
        for(auto &e : blueEdges) graph[e[0]].push_back({e[1], 0});
    
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({0, {0, 1}});
        pq.push({0, {0, 0}});
        vector<vector<int>>dist(n, vector<int>(2, 1e9));
        dist[0][0] = 0;
        dist[0][1] = 0;
        while(!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            int d = tp.first, node = tp.second.first, color = tp.second.second;
            for(auto &adj : graph[node]) {
                if(adj.second != color) {
                    if(dist[adj.first][!color] > d + 1) {
                        dist[adj.first][!color] = d + 1;
                        pq.push({d + 1, {adj.first, !color}});
                    }
                }
            }
        }
        
        vector<int>ans;
        
        for(int i = 0; i < n; ++i) {
            int mn = min(dist[i][0], dist[i][1]);
            if(mn == 1e9) ans.push_back(-1);
            else ans.push_back(mn);
        }
        
        return ans;
    }
};