class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int, int>> graph[n];
        for(auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});
        dist[0] = 0;
        while(!pq.empty()) {
            auto tp = pq.top(); pq.pop();
            int node = tp.second, d = tp.first;
            if(d >= disappear[node] || dist[node] < d) continue;
            for(auto &adj : graph[node]) {
                int adjDist = adj.second, adjNode = adj.first;
                if(d + adjDist < disappear[adjNode]) {
                    if(d + adjDist < dist[adjNode]) {
                        dist[adjNode] = d + adjDist;
                        pq.push({d + adjDist, adjNode});
                    }
                }
            }
        }
        
        for(int i = 0; i < n; ++i) {
            dist[i] = ((dist[i] == 1e9) ? -1 : dist[i]);
        }
        return dist;
    }
};