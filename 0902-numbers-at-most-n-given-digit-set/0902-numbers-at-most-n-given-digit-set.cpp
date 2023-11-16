class Solution {
public:
    int dp[11][2][2];
    string convertToString(int n) {
        string s = "";
        while(n != 0) {
            int rem = n % 10;
            s.push_back(rem + '0');
            n /= 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    int helper(string &s, vector<string>&digits, int idx, bool leading, bool tight) {
        if(idx >= s.size()) {
            return !leading;
        }
        
        if(dp[idx][leading][tight] != -1) return dp[idx][leading][tight];

        int cnt = 0;
        if(tight) {
            for(int i = 0; i < digits.size(); ++i) {
                if(!leading && (digits[i] == "0")) continue;
                if((digits[i][0] - '0') <= (s[idx] - '0')) {
                    cnt += helper(s, digits, idx + 1, leading & ((digits[i][0] - '0') == 0), (tight & ((digits[i][0] - '0') == (s[idx] - '0'))));
                }
            }
        } else {
            for(int i = 0; i < digits.size(); ++i) {
                if(!leading && digits[i] == "0") continue;
                cnt += helper(s, digits, idx + 1, leading & ((digits[i][0] - '0') == 0), tight & ((s[idx] - '0') == (digits[i][0] - '0')));
            }
        }
        return dp[idx][leading][tight] = cnt;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = convertToString(n);
        digits.push_back("0");
        memset(dp, -1, sizeof(dp));
        return helper(s, digits, 0, true, true);
    }
};