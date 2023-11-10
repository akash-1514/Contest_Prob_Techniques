class Solution {
public:
    void dfs(unordered_map<int, vector<int>>&graph, int src, int par, vector<int>&ans) {
        ans.push_back(src);
        for(auto &adj : graph[src]) {
            if(adj != par) {
                dfs(graph, adj, src, ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        for(auto &adj : adjacentPairs) {
            indegree[adj[0]]++;
            indegree[adj[1]]++;
            graph[adj[0]].push_back(adj[1]);
            graph[adj[1]].push_back(adj[0]);
        }
        vector<int> ans;
        for(auto &it : indegree) {
            if(it.second == 1) {
                dfs(graph, it.first, -1000001, ans);
                break;
            }
        }
        return ans;
    }
};