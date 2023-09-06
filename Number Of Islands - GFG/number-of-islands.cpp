//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
    bool valid(int n, int m, int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int totNodes = n * m;
        DSU ds(totNodes);
        
        vector<vector<int>>vec(n, vector<int>(m, 0));
        
        int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        
        vector<int>ans;
        int components = 0;
        for(auto &q : operators) {
            int x = q[0], y = q[1];
            int currNodeNum = x * m + y;
            if(vec[x][y]) {
                ans.push_back(components);
            } else {
                vec[x][y] = 1;
                int cnt = 0;
                for(int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(valid(n, m, nx, ny) && vec[nx][ny] == 1) {
                        int nodeNum = nx * m + ny;
                        if(ds.findPar(currNodeNum) != ds.findPar(nodeNum)) {
                            cnt++;
                            ds.unionBySize(nodeNum, currNodeNum);
                        }
                    }   
                }
                components -= (cnt - 1);
                ans.push_back(components);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends