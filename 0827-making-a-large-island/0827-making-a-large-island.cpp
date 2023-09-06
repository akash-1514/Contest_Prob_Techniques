class DSU {
public:
	vector<int> rank, size, parent;
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
    bool valid(int n, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        DSU ds(n * n), ds2(n * n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    int currNodeNum = i * n + j;
                    for(int k = 0; k < 4; ++k) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(valid(n, nx, ny) && grid[nx][ny] == 1) {
                            int nodeNum = nx * n + ny;
                            ds.unionBySize(currNodeNum, nodeNum);
                            ds2.unionBySize(currNodeNum, nodeNum);
                        }
                    }
                }
            }
        }
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int currNodeNum = i * n + j;
                if(grid[i][j] == 0) {
                    int sz = 1;
                    unordered_map<int, int>mp;
                    for(int k = 0; k < 4; ++k) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(valid(n, nx, ny) && grid[nx][ny] == 1) {
                            int nodeNum = nx * n + ny;
                            if(ds.findPar(nodeNum) != ds.findPar(currNodeNum)) {
                                int par = ds2.findPar(nodeNum);
                                if(mp.find(par) == mp.end()) {
                                    mp[par]++;
                                    sz += ds2.size[par];
                                }
                            }
                        }
                    }
                    mx = max(mx, sz);
                } else {
                    mx = max(mx, ds.size[ds.findPar(i * n + j)]);
                }
            }
        }
        
        return mx;
    }
};