map<int, set<string>>ans;
class DSU {
public:
	vector<int> rank, size, parent;
	DSU(int n) {
        ans.clear();
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
            for(auto &it : ans[par_u]) {
                ans[par_v].insert(it);
            }
			parent[par_u] = par_v;
			size[par_v] += size[par_u];
		} else {
            for(auto &it : ans[par_v]) {
                ans[par_u].insert(it);
            }
			parent[par_v] = par_u;
			size[par_u] += size[par_v];
		}
   	}
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < accounts[i].size(); ++j) {
                ans[i].insert(accounts[i][j]);
            }
        }
        unordered_map<string, int>mp;
        for(int i = 0; i < n; ++i) {
            for(int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if(mp.find(email) != mp.end()) {
                    ds.unionBySize(i, mp[email]);
                } else {
                    mp[email] = i;
                }
            }
        }
        
        vector<vector<string>>a;
        for(int i = 0; i < n; ++i) {
            if(ds.parent[i] == i) {
                if(ans[i].size() != 0) {
                    vector<string>res = {accounts[i][0]};
                    for(auto &it : ans[i]) {
                        res.push_back(it);
                    }
                    a.push_back(res);
                }
            }
        }
        return a;
    }
};