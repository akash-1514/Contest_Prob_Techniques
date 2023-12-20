class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>>route_node;
        unordered_map<int, vector<int>>node_route;
        for(int i = 0; i < routes.size(); ++i) {
            for(int j = 0; j < routes[i].size(); ++j) {
                route_node[i].push_back(routes[i][j]);
                node_route[routes[i][j]].push_back(i);
            }
        }
        
        queue<pair<int, int>>q;
        q.push({source, 0});
        
        unordered_map<int, int> vis_node, vis_route;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int node = front.first, buses = front.second;
            if(node == target) return buses;
            
            for(int r : node_route[node]) {
                if(vis_route[r] == 1) continue;
                vis_route[r] = 1;
                for(int j = 0; j < route_node[r].size(); ++j) {
                    if(vis_node[route_node[r][j]] == 1) continue;
                    vis_node[route_node[r][j]] = 1;
                    q.push({route_node[r][j], buses + 1});
                }
            }
        }
        return -1;
    }
};