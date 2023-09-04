class Solution {
public:
    bool helper(vector<pair<int, double>>graph[], int src, int des, double res, double &ans, vector<int>&vis) {
        if(src == des) {
            ans = res;
            return true;
        }
        vis[src] = 1;
        for(auto &adj : graph[src]) {
            if(!vis[adj.first]) {
                if(helper(graph, adj.first, des, res * adj.second, ans, vis)) {
                    vis[src] = 0;
                    return true;
                }
            }
        }   
        vis[src] = 0;
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int>mp;
        int cnt = 0;
        for(auto &eq : equations) {
            if(mp.find(eq[0]) == mp.end()) {
                mp[eq[0]] = cnt++;
            }
            
            if(mp.find(eq[1]) == mp.end()) {
                mp[eq[1]] = cnt++;
            }
        }
        vector<pair<int, double>> graph[cnt];
        int idx = 0;
        for(auto &eq : equations) {
            int u = mp[eq[0]], v = mp[eq[1]];
            graph[u].push_back({v, values[idx]});
            graph[v].push_back({u, 1.0 / values[idx]});
            idx++;
        }
        
        vector<double>ans;
        vector<int>vis(cnt, 0);
        for(auto &q : queries) {
            string s1 = q[0], s2 = q[1];
            if(mp.find(s1) == mp.end() || mp.find(s2) == mp.end()) {
                ans.push_back(-1.0);
            } else {
                int u = mp[s1], v = mp[s2];
                double res = -1.0;
                helper(graph, u, v, 1.0, res, vis);
                ans.push_back(res);
            }
        }
        
        return ans;
    }
};