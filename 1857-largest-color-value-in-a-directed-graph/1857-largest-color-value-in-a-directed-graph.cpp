class Solution {
public:
    unordered_map<int, vector<int>>dp;
    bool isCycle(vector<int> graph[], int src, vector<int>&vis, vector<int>&dfsVis) {
        vis[src] = dfsVis[src] = 1;
        for(auto &adj : graph[src]) {
            if(!vis[adj]) {
                if(isCycle(graph, adj, vis, dfsVis)) return true;
            } else if(dfsVis[adj]) {
                return true;
            }
        }
        dfsVis[src] = 0;
        return false;
    }
    
    vector<int> dfs(vector<int> graph[], string &color, int src) {
        if(dp.find(src) != dp.end()) return dp[src];
        vector<int> freq(26, 0);
        for(auto &adj : graph[src]) {
            vector<int> res = dfs(graph, color, adj);
            for(int i = 0; i < 26; ++i) {
                freq[i] = max(res[i], freq[i]);
            } 
        }
        freq[color[src] - 'a']++;
        return dp[src] = freq;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> graph[n];
        for(auto &e : edges) graph[e[0]].push_back(e[1]);
        vector<int> vis(n, 0), dfsVis(n, 0);
        for(int i = 0; i < n; ++i) {
            if(isCycle(graph, i, vis, dfsVis)) return -1;
        }
        
        for(int i = 0; i < n; ++i) vis[i] = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            vector<int> res = dfs(graph, colors, i);
            for(int j = 0; j < 26; ++j) {
                ans = max(ans, res[j]);
            }
        }
        
        return ans;
    }
};