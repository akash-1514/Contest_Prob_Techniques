class Solution {
public:
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<vector<int>> graph1 = buildGraph(rowConditions, k);
        vector<vector<int>> graph2 = buildGraph(colConditions, k);

        
        vector<int> rowTopo = topoSort(graph1, rowConditions, k);
        vector<int> colTopo = topoSort(graph2, colConditions, k);
        
        if(rowTopo.size() == 0 || colTopo.size() == 0) return {};
        
        vector<vector<int>>ans(k, vector<int>(k, 0));
        
        vector<int> colTrack(k + 1, 0), rowTrack(k + 1, 0);
        
        for(int i = 0; i < k; ++i) {
            rowTrack[rowTopo[i]] = i;
            colTrack[colTopo[i]] = i;
        }
        
        for(int i = 1; i <= k; ++i) {
            ans[rowTrack[i]][colTrack[i]] = i;
        }
        
        return ans;
    }
    
    
    vector<int> topoSort(vector<vector<int>>&graph, vector<vector<int>>& edges, int k) {
        vector<int> indegree(k + 1, 0);
        for(auto &e : edges) {
            indegree[e[1]]++;
        }
        
        queue<int>q;
        for(int i = 1; i <= k; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            topo.push_back(front);
            
            for(auto &adj : graph[front]) {
                if(--indegree[adj] == 0) {
                    q.push(adj);
                }
            }
        }
        
        for(int i = 1; i <= k; ++i) {
            if(indegree[i] != 0) return {};
        }
        
        return topo;
    }
    
    
    vector<vector<int>> buildGraph(vector<vector<int>>&edges, int k) {
        vector<vector<int>> graph(k + 1);
        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
        }
        return graph;
    }
};