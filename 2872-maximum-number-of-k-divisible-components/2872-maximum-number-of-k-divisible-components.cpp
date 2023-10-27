class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n == 1) return 1;
        vector<int>indegree(n, 0);
        vector<int> graph[n];

        for(auto &e : edges) {
            indegree[e[0]]++, indegree[e[1]]++;
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        queue<int>q;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }
        
        int ans = 0;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            if(values[front] % k == 0) {
                ans++;
                values[front] = 0;
            } 
            
            for(auto &adj : graph[front]) {
                if(indegree[adj] != 0) {
                    indegree[adj]--, indegree[front]--;
                    values[adj] += values[front] % k;
                    if(indegree[adj] == 1) {
                        q.push(adj);
                    }
                }
            }
        }
        
        return ans;
    }
};