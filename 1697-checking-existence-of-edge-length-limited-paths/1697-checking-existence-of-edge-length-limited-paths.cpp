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
    static bool cmp(vector<int>&v1, vector<int>&v2) {
        return v1[2] < v2[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int len = queries.size();
        sort(edgeList.begin(), edgeList.end(), cmp);
        vector<vector<int>> vec;
        for(int i = 0; i < queries.size(); ++i) {
            vector<int> v = {queries[i][2], queries[i][0], queries[i][1], i};
            vec.push_back(v);
        }
        
        sort(vec.begin(), vec.end());
        DSU ds(n);
        
        vector<bool> ans(len, 0);
        int idx = 0;
        for(int i = 0; i < vec.size(); ++i) {
            int u = vec[i][1], v = vec[i][2], len = vec[i][0], q_idx = vec[i][3];
            while(idx < edgeList.size() && edgeList[idx][2] < len) {
                ds.unionBySize(edgeList[idx][0], edgeList[idx][1]);
                idx++;
            }
            if(ds.findPar(u) == ds.findPar(v)) {
                ans[q_idx] = true;
            } else {
                ans[q_idx] = false;
            }
        }
        return ans;
    }
};