class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }
        vector<int> graph[n];
        vector<int> indegree(n, 0), vis(n, 0);
        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++, indegree[e[1]]++;
        }
        queue<int>q;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()) {
            vector<int> res;
            int sz = q.size();
            while(sz--) {
                auto front = q.front();
                q.pop();
                
                res.push_back(front);

                for(auto &adj : graph[front]) {
                    if(--indegree[adj] == 1) {
                        q.push(adj);
                    }
                }
            }
            ans = res;
        }
        return ans;
    }
};