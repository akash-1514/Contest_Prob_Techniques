class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& Tasks) {
        int n = Tasks.size();
        vector<vector<int>>tasks;
        for(int i = 0; i < n; ++i) {
            tasks.push_back({Tasks[i][0], Tasks[i][1], i});
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        vector<int>ans;
        
        long long time = 0, idx = 0;
        
        while(!pq.empty() || idx < n) {
            if(!pq.empty()) {
                auto tp = pq.top(); pq.pop();
                int pTime = tp.first, t = tp.second;
                time += pTime;
                ans.push_back(t);
                while(idx < n && tasks[idx][0] <= time) {
                    pq.push({tasks[idx][1], tasks[idx][2]});
                    idx++;
                }
            } else {
                time = tasks[idx][0];
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }
        }
        
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};