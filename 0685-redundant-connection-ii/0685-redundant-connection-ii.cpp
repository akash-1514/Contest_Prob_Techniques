class DSU {
private:
	vector<int> rank, size, parent;
public:
	DSU(int n) {
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // dsu doesn't helps us to detect cycle in directed graph
        // but if a cycle is guranteed then dsu will help to detect it.
        
        // check for two parent
        
        vector<int> indegree(n + 1, -1);
        
        int ans1 = -1, ans2 = -1, ans3 = -1;
        for(int i = 0; i < n; ++i) {
            int u = edges[i][0], v = edges[i][1];
            if(indegree[v] == -1) {
                indegree[v] = i;
            } else {
                ans1 = i, ans2 = indegree[v];
                break;
            }
        }
        
        DSU ds(n);
        bool fl = false;
        for(int i = 0; i < n; ++i) {
            if(i != ans1) {
                int u = edges[i][0], v = edges[i][1];
                if(ds.findPar(u) != ds.findPar(v)) {
                    ds.unionBySize(u, v);
                } else {
                    ans3 = i;
                    fl = true;
                    break;
                }
            }
        }
        if(ans1 != -1) {
            if(fl) {
                return edges[ans2];
            } else {
                return edges[ans1];
            }
        } else {
            return edges[ans3];
        }
    }
};