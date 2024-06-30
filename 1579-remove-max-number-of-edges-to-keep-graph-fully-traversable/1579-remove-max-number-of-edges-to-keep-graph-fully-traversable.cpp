class DSU {
public:
	vector<int> rank, size, parent;
    int components;
	DSU(int n) {
        components = n;
		rank.resize(n + 1, 0);
		size.resize(n + 1);
		parent.resize(n + 1, 0);
		for (int i = 0; i <= n; ++i) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int findPar(int u) {
		if (parent[u] == u) return u;
		return parent[u] = findPar(parent[u]);
	}

	void unionByRank(int u, int v) {
		int par_u = findPar(u);
		int par_v = findPar(v);
		if (par_u == par_v) return;
        components--;
		int rank_u = rank[par_u];
		int rank_v = rank[par_v];
		if (rank_v == rank_u) {
			rank[par_u]++;
			parent[par_v] = par_u;
		} else if (rank_u > rank_v) {
			parent[par_v] = par_u;
		} else {
			parent[par_u] = par_v;
		}
	}

	void unionBySize(int u, int v) {
		int par_u = findPar(u);
		int par_v = findPar(v);

		if(par_u == par_v) return;

		int size_u = size[par_u];
		int size_v = size[par_v];

		if(size_v > size_u) {
			parent[par_u] = par_v;
			size[par_v] += size[par_u];
		} else {
			parent[par_v] = par_u;
			size[par_u] += size[par_v];
		}
   	}
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU ds1(n), ds2(n);
        int ans = 0;
        for(auto &e : edges) {
            if(e[0] == 3) {
                int par_u = ds1.findPar(e[1]);
                int par_v = ds1.findPar(e[2]);
                
                if(par_u != par_v) {
                    ds1.unionByRank(par_u, par_v);
                    ds2.unionByRank(par_u, par_v);
                } else {
                    ans++;
                }
            }
        }
        
        for(auto &e : edges) {
            int type = e[0], u = e[1], v = e[2];
            if(type == 1) {
                int par_u = ds1.findPar(u);
                int par_v = ds1.findPar(v);
                if(par_u != par_v) {
                    ds1.unionByRank(par_u, par_v); 
                } else {
                    ans++;
                }
            } else if(type == 2) {
                int par_u = ds2.findPar(u);
                int par_v = ds2.findPar(v);
                if(par_u != par_v) {
                    ds2.unionByRank(par_u, par_v); 
                } else {
                    ans++;
                }
            }
        }
        
        if(ds1.components > 1 || ds2.components > 1) {
            return -1;
        }
        
        return ans;
    }
};