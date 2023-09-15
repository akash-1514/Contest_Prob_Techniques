//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        DSU ds(V);
        vector<vector<int>>edges;
        for(int i = 0; i < V; ++i) {
            for(auto &it : adj[i]) {
                int wt = it[1], u = i, v = it[0];
                vector<int> ed = {wt, u, v};
                edges.push_back(ed);
            }
        }
        
        sort(edges.begin(), edges.end());
        
        int sum = 0;
        for(auto &e : edges) {
            if(ds.findPar(e[1]) != ds.findPar(e[2])) {
                // cout << e[1] << " " << e[2] << " " << e[0] << endl;
                sum += (int)e[0];
                ds.unionByRank(e[1], e[2]);
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends