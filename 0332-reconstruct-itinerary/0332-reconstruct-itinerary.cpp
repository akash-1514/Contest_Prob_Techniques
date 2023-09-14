class Solution {
public:
    bool dfs(unordered_map<string, multiset<string>>&graph, string src, vector<string>&ans, unordered_map<string, int>&vis, int n) {
        ans.push_back(src);
        if(n == 0) return true;
        for(auto &adj : graph[src]) {
            string path = src + "," + adj;
            if(vis[path] > 0) {
                vis[path]--;
                if(dfs(graph, adj, ans, vis, n - 1)) return true;
                vis[path]++;
            }
        }
        ans.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, multiset<string>>graph;
        unordered_map<string, int>vis;
        for(auto &ticket : tickets) {
            string path = ticket[0] + "," + ticket[1];
            graph[ticket[0]].insert(ticket[1]);
            vis[path]++;
        }
        vector<string> ans;
        dfs(graph, "JFK", ans, vis, n);
        return ans;
    }
};