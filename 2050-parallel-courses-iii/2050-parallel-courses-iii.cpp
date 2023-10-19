class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> maxTime(n + 1, 0), indegree(n + 1, 0);
        vector<int> graph[n + 1];
        for(auto &r : relations) {
            indegree[r[1]]++;
            graph[r[0]].push_back(r[1]);
        }
        queue<int>q;
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
                maxTime[i] = time[i - 1];
            }
            ans = max(ans, time[i - 1]);
        }
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            for(auto &adj : graph[front]) {
                if(--indegree[adj] == 0) {
                    q.push(adj);
                }
                maxTime[adj] = max(maxTime[adj], maxTime[front] + time[adj - 1]);
                ans = max(ans, maxTime[adj]);
            }
        }
        return ans;
    }
};