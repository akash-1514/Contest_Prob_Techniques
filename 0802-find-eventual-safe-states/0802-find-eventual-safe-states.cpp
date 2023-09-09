class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> revGraph[n];
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < graph[i].size(); ++j) {
                revGraph[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;
        
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()) {
            auto front = q.front();
            ans.push_back(front);
            q.pop();
            
            for(auto &it : revGraph[front]) {
                if(--indegree[it] == 0) q.push(it);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};