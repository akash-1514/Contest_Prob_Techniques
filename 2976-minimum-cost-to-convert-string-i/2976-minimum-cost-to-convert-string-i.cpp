#define ppi pair<long long, long long>
class Solution {
private:
    unordered_map<long long, unordered_map<long long, long long>> dp;
    unordered_map<long long, unordered_map<long long, long long>> graph;
public:
    long long dfs(int src, int tar) {
        vector<long long> dist(26, 1e18);
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            
            int node = tp.second, d = tp.first;
            for(auto &adj : graph[node]) {
                long long n = adj.first, c = adj.second;
                if(d + c < dist[n]) {
                    dist[n] = d + c;
                    pq.push({dist[n], n});
                }
            }
        }
        return dist[tar];
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        for(int i = 0; i < n; ++i) {
            int u = original[i] - 'a', v = changed[i] - 'a';
            if(graph[u].find(v) != graph[u].end()) graph[u][v] = min(graph[u][v], (long long)cost[i]);
            else graph[u][v] = cost[i];
        }
        
        long long ans = 0;
        for(int i = 0; i < source.size(); ++i) {
            int s = source[i] - 'a', t = target[i] - 'a';
            if(dp[s].find(t) != dp[s].end()) {
                if(dp[s][t] == 1e18) return -1;
                ans += dp[s][t];
            } else {
                long long minCost = dfs(s, t);
                dp[s][t] = minCost;
                if(minCost == 1e18) return -1;
                ans += minCost;
            }
        }
        return ans;
    }
};