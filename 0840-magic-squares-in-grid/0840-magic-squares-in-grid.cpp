class Solution {
public:
    bool checkRowColSum(vector<vector<int>>&grid, int r, int c, int sum) {
        for(int i = r; i < r + 3; ++i) {
            int rowSum = 0;
            for(int j = c; j < c + 3; ++j) {
                rowSum += grid[i][j];
            }
            if(rowSum != sum) return false;
        }
        
        for(int i = c; i < c + 3; ++i) {
            int colSum = 0;
            for(int j = r; j < r + 3; ++j) {
                colSum += grid[j][i];
            }
            if(colSum != sum) return false;
        }
        
        int i = r, j = c + 2;
        int dia = 0;
        while(i < r + 3) {
            dia += grid[i][j];
            i++, j--;
        }
        
        if(dia != sum) return false;
        return true;
    }
    bool check(vector<vector<int>>&grid, int r, int c) {
        unordered_set<int>st;
        for(int i = r; i < r + 3; ++i) {
            for(int j = c; j < c + 3; ++j) {
                if(grid[i][j] >= 1 && grid[i][j] <= 9) {
                    st.insert(grid[i][j]);
                }
            }
        }
        
        int diagonalSum = 0;
        
        int i = r, j = c;
        int dia = 0;
        while(i < r + 3) {
            dia += grid[i][j];
            i++, j++;
        }
        
        bool res = checkRowColSum(grid, r, c, dia);
        
        return (st.size() == 9) && res;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i <= n - 3; ++i) {
            for(int j = 0; j <= m - 3; ++j) {
                if(check(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};