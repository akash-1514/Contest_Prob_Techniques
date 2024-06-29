class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<int> graph[], int src, int node) {
        for(auto &adj : graph[src]) {
            if(ans[adj].empty() || ans[adj].back() != node) {
                ans[adj].push_back(node);
                dfs(graph, adj, node);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ans.resize(n);
        vector<int> graph[n];
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i = 0; i < n; ++i) {   
            dfs(graph, i, i);
        }
        
        return ans;
    }
};