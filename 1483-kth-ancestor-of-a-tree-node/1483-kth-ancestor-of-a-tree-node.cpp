class TreeAncestor {
private:
    vector<vector<int>>up;
    vector<vector<int>> graph;
    int maxUp;
public:
    TreeAncestor(int n, vector<int>& parent) {
        maxUp = log2(n) + 1;
        up.resize(n, vector<int>(maxUp + 1, 0));
        graph.resize(n);
        for(int i = 1; i < n; ++i) {
            graph[parent[i]].push_back(i);
            graph[i].push_back(parent[i]);
        }
        binaryLifting(0, -1);
    }
    
    void binaryLifting(int src, int par) {
        up[src][0] = par;
        for(int i = 1; i <= maxUp; ++i) {
            if(up[src][i - 1] != -1) {
                up[src][i] = up[up[src][i - 1]][i - 1];
            } else {
                up[src][i] = -1;
            }
        }
        
        for(int child : graph[src]) {
            if(child != par) {
                binaryLifting(child, src);
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(node == -1 || k == 0) return node;
        
        for(int i = maxUp; i >= 0; --i) {
            if(k >= (1 << i)) {
                return getKthAncestor(up[node][i], k - (1 << i));
            }
        }
        return -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */