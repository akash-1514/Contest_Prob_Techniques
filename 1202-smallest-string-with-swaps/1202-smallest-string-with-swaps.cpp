class Solution {
public:
    void dfs(vector<int> graph[], int src, vector<int>&vis, vector<int>&vec) {
        vis[src] = 1;
        vec.push_back(src);
        for(auto &adj : graph[src]) {
            if(!vis[adj]) {
                dfs(graph, adj, vis, vec);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> graph[n];
        for(auto &p : pairs) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        
        vector<int>vis(n, 0);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                vector<int> vec;
                dfs(graph, i, vis, vec);
                vector<char> character;
                for(int i : vec) {
                    character.push_back(s[i]);
                }
                sort(vec.begin(), vec.end());
                sort(character.begin(), character.end());
                for(int i = 0; i < vec.size(); ++i) {
                    s[vec[i]] = character[i];
                }
            }
        }
        
        return s;
    }
};