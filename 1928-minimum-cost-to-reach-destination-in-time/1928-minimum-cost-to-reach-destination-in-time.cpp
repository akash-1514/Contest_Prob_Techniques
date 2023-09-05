#define ppi pair<int, pair<int, int>>
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& payingFees) {
        int n = payingFees.size();
        vector<pair<int, int>> graph[n];
        for(auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<int>cost(n, 1e9), time(n, 1e9);
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        pq.push({payingFees[0], {0, 0}});
        cost[0] = payingFees[0], time[0] = 0;
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            
            int currCost = tp.first, currTime = tp.second.first, node = tp.second.second;
            
            for(auto &adj : graph[node]) {
                // we will not consider paths which takes time > maxTime
                if(currTime + adj.second > maxTime) continue;
                if(currCost + payingFees[adj.first] < cost[adj.first]) {
                    cost[adj.first] = currCost + payingFees[adj.first];
                    time[adj.first] = currTime + adj.second;
                    pq.push({cost[adj.first], {time[adj.first], adj.first}});
                } else if(currTime + adj.second < time[adj.first]) {
                    time[adj.first] = currTime + adj.second;
                    pq.push({currCost + payingFees[adj.first], {time[adj.first], adj.first}});
                }
            }
        }
        
        return cost[n - 1] == 1e9 ? -1 : cost[n - 1];
    }
};