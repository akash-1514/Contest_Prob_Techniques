#define ppi pair<int, int>
class Graph {
public:
    vector<vector<pair<int, int>>> graph;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        graph.resize(n);
        for(auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        vector<int> dist(N, 1e9);
        dist[node1] = 0;
        pq.push({0, node1});
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            int node = tp.second, d = tp.first;
            
            for(auto &adj : graph[node]) {
                if(d + adj.second < dist[adj.first]) {
                    dist[adj.first] = d + adj.second;
                    pq.push({dist[adj.first], adj.first});
                }
            }
        }
        
        return dist[node2] == 1e9 ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */