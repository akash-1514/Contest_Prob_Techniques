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
    bool similar(string &s1, string &s2) {
        if(s1 == s2) return true;
        int cnt = 0;
        for(int i = 0; i < s1.size(); ++i) {
            if(s1[i] != s2[i]) cnt++;
        }
        return cnt == 2;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU ds(n);
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(similar(strs[i], strs[j])) {
                    ds.unionByRank(i, j);
                }
            }
        }
        
        return ds.components;
    }
};