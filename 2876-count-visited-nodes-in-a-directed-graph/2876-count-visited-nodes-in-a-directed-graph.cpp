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
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> graph[n];
        vector<int> cycle;
        DSU ds(n);
        int idx = 0;
        for(auto &e : edges) {
            ds.unionBySize(idx, edges[idx]);
            graph[idx].push_back(edges[idx]);
            graph[edges[idx]].push_back(idx);
            idx++;
        }
        vector<int> vis(n, 0);
        for(int i = 0; i < n; ++i) {
            if(ds.parent[i] == i) {
                int node = i;
                while(!vis[node]) {
                    vis[node] = 1;
                    node = edges[node];
                }
                cycle.push_back(node);
            }
        }
        queue<pair<int, int>>q;
        vector<int>ans(n, 0);
        vector<int> vis2(n, 0);
        for(auto &n : cycle) {
            int node = n, len = 1;
            while(edges[node] != n) {
                len++;
                node = edges[node];
            }
            node = n;
            while(edges[node] != n) {
                ans[node] = len;
                vis2[node] = 1;
                q.push({node, len});
                node = edges[node];
            }
            vis2[node] = 1;
            ans[node] = len;
            q.push({node, len});
        }
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int node = front.first, d = front.second;
            for(auto &adj : graph[node]) {
                if(!vis2[adj]) {
                    vis2[adj] = 1;
                    ans[adj] = d + 1;
                    q.push({adj, d + 1});
                }
            }
        }
        
        return ans;
    }
};