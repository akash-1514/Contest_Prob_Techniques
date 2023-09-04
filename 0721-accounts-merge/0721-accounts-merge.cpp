class Solution {
public:
    map<int, set<string>>ans;
    void dfs(vector<vector<string>>&accounts, vector<int> graph[], int src, int curr, vector<int>&vis) {
        vis[src] = 1;
        for(int i = 1; i < accounts[src].size(); ++i) {
            ans[curr].insert(accounts[src][i]);
        }
        
        for(auto &adj : graph[src]) {
            if(!vis[adj]) {
                dfs(accounts, graph, adj, curr, vis);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> graph[n];
        unordered_map<string, int>mp;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < accounts[i].size(); ++j) {
                if(mp.find(accounts[i][j]) != mp.end()) {
                    graph[i].push_back(mp[accounts[i][j]]);
                    graph[mp[accounts[i][j]]].push_back(i);
                } else {
                    mp[accounts[i][j]] = i;
                }
            }
        }
        
        vector<int> vis(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(accounts, graph, i, i, vis);
            }
        }
        
        vector<vector<string>>res;
        
        for(auto &it : ans) {
            vector<string>r = {accounts[it.first][0]};
            for(auto &it2 : it.second) {
                r.push_back(it2);
            }
            res.push_back(r);
        }
        
        return res;
    }
};