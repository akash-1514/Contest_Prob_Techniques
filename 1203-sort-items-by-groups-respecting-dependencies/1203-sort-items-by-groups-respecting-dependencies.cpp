class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& before) {
        
        // assigning groups to loners
        for(int i = 0; i < n; ++i) {
            if(group[i] == -1) {
                group[i] = m++;
            }
        }
        
        vector<int> graph[n];
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < before[i].size(); ++j) {
                graph[before[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> itemOrder;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            itemOrder.push_back(front);
            for(auto &adj : graph[front]) {
                if(--indegree[adj] == 0) q.push(adj);
            }
        }
        
        if(itemOrder.size() != n) return {};
        
        vector<int> groupGraph[m];
        vector<int> indegree2(m, 0);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < before[i].size(); ++j) {
                if(group[i] != group[before[i][j]]) {
                    groupGraph[group[before[i][j]]].push_back(group[i]);
                    indegree2[group[i]]++;
                }
            }
        }
        
        queue<int>q2;
        for(int i = 0; i < m; ++i) {
            if(indegree2[i] == 0) {
                q2.push(i);
            }
        }
        
        vector<int> groupOrder;
        while(!q2.empty()) {
            auto front = q2.front();
            q2.pop();
            
            groupOrder.push_back(front);
            
            for(auto &adj : groupGraph[front]) {
                if(--indegree2[adj] == 0) {
                    q2.push(adj);
                }
            }
        }
        
        if(groupOrder.size() != m) return {};
        
        unordered_map<int, vector<int>>res;
        for(int i = 0; i < itemOrder.size(); ++i) {
            int g = group[itemOrder[i]];
            res[g].push_back(itemOrder[i]);
        }
        
        vector<int>ans;
        
        for(int i = 0; i < m; ++i) {
            for(auto &it : res[groupOrder[i]]) {
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};