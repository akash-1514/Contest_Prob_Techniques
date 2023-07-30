class Solution {
public:
    int mod = 1e9 + 7;
    bool check(string &str) {
        for(int i = 0; i < str.size() - 1; ++i) {
            if(abs((str[i] - '0') - (str[i + 1] - '0')) != 1) return false;
        }
        return true;
    }
    int helper(string &low, string &high, int idx, bool tight, int prev, bool leading, vector<vector<vector<vector<int>>>>&dp) {
        if(idx >= high.size()) {
            if(leading) return 0;
            return 1;
        }
        if(dp[idx][tight][prev][leading] != -1) return dp[idx][tight][prev][leading];
        int r = (tight) ? high[idx] - '0' : 9, cnt = 0;
        for(int i = 0; i <= r; ++i) {
            if(leading) {
                cnt = (cnt + helper(low, high, idx + 1, tight & (i == r), i, leading & (i == 0), dp)) % mod;
            } else if(abs(prev - i) == 1) {
                cnt = (cnt + helper(low, high, idx + 1, tight & (i == r), i, false, dp)) % mod;
            }
        }
        
        return dp[idx][tight][prev][leading] = cnt;
    }
    int countSteppingNumbers(string low, string high) {
        int n = high.size();
        string ext = "";
        int d = high.size() - low.size();
        while(d--) {
            ext += '0';
        }
        
        string str = "";
        for(int i = 0; i < high.size(); ++i) {
            str += "0";
        }
        
        vector<vector<vector<vector<int>>>>dp1(n + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(11, vector<int>(2, -1))));
        vector<vector<vector<vector<int>>>>dp2(n + 1, vector<vector<vector<int>>>(2, vector<vector<int>>(11, vector<int>(2, -1))));

        
        ext += low;
        int res1 = helper(str, high, 0, 1, 0, true, dp1);
        int res2 = helper(str, ext, 0, 1, 0, true, dp2);
        
        return (res1 - res2 + check(low) + mod) % mod;  
    }
};