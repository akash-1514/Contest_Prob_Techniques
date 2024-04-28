class Solution {
public:
    long long subTreeSizes[30001];
    long long subTreeAns[30001];
    long long ans[30001];
    void dfs1(vector<int>graph[], int src, int parent) {
        int nodes = 0;
        int s = 0;
        for(auto &adj : graph[src]) {
            if(adj != parent) {
                dfs1(graph, adj, src);
                nodes += subTreeSizes[adj];
                s += (subTreeAns[adj] + subTreeSizes[adj]);
            }
        }
        subTreeSizes[src] = 1 + nodes;
        subTreeAns[src] = s;
    }
    
    
    
    void dfs2(vector<int> graph[], int src, int parent, int partialAns, int totNodes) {
        ans[src] = subTreeAns[src] + partialAns + (totNodes - subTreeSizes[src]);
        for(auto &adj : graph[src]) {
            if(adj != parent) {
                dfs2(graph, adj, src, ans[src] - (subTreeAns[adj] + subTreeSizes[adj]), totNodes);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];
        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        dfs1(graph, 0, -1);
        dfs2(graph, 0, -1, 0, n);
        
        vector<int>res;
        for(int i = 0; i < n; ++i) {
            res.push_back(ans[i]);
        }
        
        return res;
    }
};