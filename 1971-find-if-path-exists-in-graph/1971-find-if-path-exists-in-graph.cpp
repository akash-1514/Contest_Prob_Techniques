class Solution {
public:
    bool dfs(vector<int> graph[], int src, int dest, vector<int>&vis) {
        if(src == dest) return true;
        vis[src] = 1;
        for(auto &c : graph[src]) {
            if(!vis[c]) {
                if(dfs(graph, c, dest, vis)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> graph[n];
        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<int>vis(n, 0);
        
        return dfs(graph, source, destination, vis);
    }
};