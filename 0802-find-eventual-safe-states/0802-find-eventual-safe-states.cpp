class Solution {
public:
    bool dfs(vector<vector<int>>&graph, int src, vector<int>&vis, vector<int>&dfsVis, vector<int>&res) {
        vis[src] = 1;
        dfsVis[src] = 1;
        
        for(auto &it : graph[src]) {
            if(!vis[it]) {
                if(dfs(graph, it, vis, dfsVis, res)) {
                    res[src] = 1;
                    return true;
                }
            } else if(dfsVis[it]) {
                res[src] = 1;
                return true;
            }
        }
        dfsVis[src] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), dfsVis(n, 0);
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(graph, i, vis, dfsVis, res);
            }
        }
        
        vector<int>ans;
        for(int i = 0; i < n; ++i) {
            if(res[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};