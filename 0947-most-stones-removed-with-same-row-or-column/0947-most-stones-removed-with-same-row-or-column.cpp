class Solution {
public:
    void dfs(vector<int> graph[], int src, vector<int>&vis) {
        vis[src] = 1;
        for(auto &adj : graph[src]) {
            if(!vis[adj]) {
                dfs(graph, adj, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> graph[n];
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        int components = 0;
        vector<int>vis(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                components++;
                dfs(graph, i, vis);
            }
        }
        return stones.size() - components;
    }
};