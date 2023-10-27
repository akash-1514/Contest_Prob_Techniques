class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        int st = 0, ed = 0, mx = 0;
        for(int i = 0; i < n; ++i) {
            int row = 0, col = i;
            while(row < n && col < n) {
                if(i == 0) {
                    dp[row][col] = 1;
                } else if(i == 1) {
                    if(s[row] == s[col]) {
                        dp[row][col] = 1;
                    }
                } else {
                    if(s[row] == s[col] && dp[row + 1][col - 1] == 1) {
                        dp[row][col] = 1;
                    }
                }
                if(dp[row][col] == 1 && col - row + 1 > mx) {
                    mx = col - row + 1;
                    st = row, ed = col;
                }
                row++, col++;
            }
        }
        
        return s.substr(st, ed - st + 1);
    }
};