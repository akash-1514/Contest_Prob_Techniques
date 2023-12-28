class Solution {
public:
    int dp[27][11][101][101];
    int helper(int n, string &s, int idx, int cnt, int prevChar, int k) {
        if(idx >= n) {
            return 0;
        }
        
        if(cnt >= 10) cnt = 10;
        
        if(dp[prevChar][cnt][idx][k] != -1) return dp[prevChar][cnt][idx][k];
        
        int ans = 1e9;
        
        if(prevChar == (s[idx] - 'a')) {
            if(cnt == 1 || cnt == 9 || cnt == 99) {
                ans = min(ans, 1 + helper(n, s, idx + 1, cnt + 1, prevChar, k));
            } else {
                ans = min(ans, helper(n, s, idx + 1, cnt + 1, prevChar, k));
            }
        } else {
            ans = min(ans, 1 + helper(n, s, idx + 1, 1, (s[idx] - 'a'), k));
        }
        
        if(k > 0) ans = min(ans, helper(n, s, idx + 1, cnt, prevChar, k - 1));
        
        return dp[prevChar][cnt][idx][k] = ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        
        bool fl = true;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != s[0]) {
                fl = false;
                break;
            }
        }
        
        if(fl) {
            if((n - k) >= 100) return 4;
            else if((n - k) >= 10) return 3;
            else if((n - k) > 1 && (n - k) < 10) return 2;
            else if((n - k) == 1) return 1;
            return 0;
        }
        
        memset(dp, -1, sizeof(dp));
        return helper(n, s, 0, 0, 26, k);
    }
};