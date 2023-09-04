class Solution {
public:
    bool dfs(vector<int> graph[], int src, int par, int col, vector<int>&vis) {
        vis[src] = col;
        for(auto &adj : graph[src]) {
            if(vis[adj] == -1) {
                if(!dfs(graph, adj, src, 1 - col, vis)) return false;
            } else if(vis[adj] == col) {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n + 1];
        for(auto &d : dislikes) {
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        } 
        
        vector<int> vis(n + 1, -1);
        for(int i = 1; i <= n; ++i) {
            if(vis[i] == -1) {
                if(!dfs(graph, i, -1, 1, vis)) return false;
            }
        }
        return true;
    }
};