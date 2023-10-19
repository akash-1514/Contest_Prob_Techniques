class DSU {
public:
    vector<int> size, parent;
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }
    
    void merge(int u, int v) {
        int par_u = findPar(u), par_v = findPar(v);
        if(par_u == par_v) return;
        
        if(size[par_u] > size[par_v]) {
            size[par_u] += size[par_v];
            parent[par_v] = par_u;
        } else {
            size[par_v] += size[par_u];
            parent[par_u] = par_v;
        }
    }
    
    int findPar(int u) {
        if(parent[u] == u) return u;
        return parent[u] = findPar(parent[u]);
    }
};
class Solution {
public:
    bool isPrime(int x) {
        if(x == 0 || x == 1) return false;
        for(int i = 2; i * i <= x; ++i) {
            if(x % i == 0) return false;
        }
        return true;
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        vector<int> graph[n + 1];
        for(auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            if(isPrime(e[0]) || isPrime(e[1])) continue;
            ds.merge(e[0], e[1]);
        }
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(isPrime(i)) {
                vector<int> nodes;
                long long sum = 0, res = 0;
                for(auto &adj : graph[i]) {
                    if(isPrime(adj)) continue;
                    sum += ds.size[ds.findPar(adj)];
                    nodes.push_back(ds.size[ds.findPar(adj)]);
                }
                for(int i = 0; i < nodes.size(); ++i) {
                    res = res + nodes[i] * (sum - nodes[i]);
                }
                ans += (res / 2) + sum;
            }
        }
        return ans;
    }
};