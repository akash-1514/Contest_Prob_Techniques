class Solution {
public:
    int bfs(vector<int> graph[], int n) {
        queue<pair<int, int>>q;
        q.push({0, 0});
        vector<int> vis(n, 0);
        vis[0] = 0;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int node = front.first, d = front.second;
            
            if(node == n - 1) {
                return d;
            }
            
            for(auto &adj : graph[node]) {
                if(!vis[adj]) {
                    vis[adj] = 1;
                    q.push({adj, d + 1});
                }
            }
        }
        
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int> graph[n];
        for(int i = 0; i < n - 1; ++i) {
            graph[i].push_back(i + 1);
        }
        for(auto &q : queries) {
            graph[q[0]].push_back(q[1]);
            int res = bfs(graph, n);
            ans.push_back(res);
        }

        return ans;
    }
};