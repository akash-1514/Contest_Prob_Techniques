//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>&grid, int x, int y, string &path) {
        int n = grid.size(), m = grid[0].size();
        grid[x][y] = 0;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                grid[nx][ny] = 0;
                if(dx[i] == 1 && dy[i] == 0) path += 'D';
                else if(dx[i] == 0 && dy[i] == 1) path += 'R';
                else if(dx[i] == -1 && dy[i] == 0) path += 'U';
                else path += 'L';
                dfs(grid, nx, ny, path);
                // backtracking
                path += 'B';
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_map<string, int>mp;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    string path = "";
                    dfs(grid, i, j, path);
                    mp[path]++;
                    path = "";
                }
            }
        }
        return mp.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends