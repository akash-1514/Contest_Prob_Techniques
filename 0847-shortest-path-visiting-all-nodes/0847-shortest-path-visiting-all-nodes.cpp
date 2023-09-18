class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, pair<int, int>>>q;
    
        set<pair<int, int>> vis;
        
        for(int i = 0; i < n; ++i) {
            vis.insert({i, (1 << i)});
            q.push({0, {i, (1 << i)}});
        }
       
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int dist = front.first, node = front.second.first, mask = front.second.second;
            
            for(auto &adj : graph[node]) {
                if((mask | (1 << adj)) == ((1 << n) - 1)) {
                    return dist + 1;
                }
                if(vis.find({adj, mask | (1 << adj)}) == vis.end()) {
                    vis.insert({adj, (mask | (1 << adj))});
                    q.push({dist + 1, {adj, mask | (1 << adj)}});
                }
            }
        }
        
        return 0;
    }
};