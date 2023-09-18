class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, pair<int, int>>>q;
        
        map<string, int>vis;
        
        for(int i = 0; i < n; ++i) {
            string temp = to_string(-1) + "," + to_string(i) + "," + to_string(1 << i);
            vis[temp] = 1;
            q.push({0, {i, (1 << i)}});
        }
       
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int dist = front.first, node = front.second.first, mask = front.second.second;
            
            if(mask == ((1 << n) - 1)) {
                return dist;
            }
            
            for(auto &adj : graph[node]) {
                string temp = to_string(node) + "," + to_string(adj) + "," + to_string(mask | (1 << adj));
                if(vis[temp] == 0) {
                    vis[temp] = 1;
                    q.push({dist + 1, {adj, mask | (1 << adj)}});
                }
            }
        }
        
        return 0;
    }
};