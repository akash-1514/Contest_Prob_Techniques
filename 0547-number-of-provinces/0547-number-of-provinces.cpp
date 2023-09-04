class Solution {
public:
    void dfs(vector<vector<int>>&graph, int src, vector<int>&vis) {
        vis[src] = 1;
        for(int nodes = 0; nodes < graph[src].size(); ++nodes) {
            if(nodes == src) continue;
            if(!vis[nodes] && graph[src][nodes] == 1) {
                dfs(graph, nodes, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), components = 0;
        vector<int>vis(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                components++;
                dfs(isConnected, i, vis);
            }
        }
        return components;
    }
};