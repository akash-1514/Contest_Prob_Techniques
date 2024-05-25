class Solution {
public:
    unordered_map<string, int>dp;
    int helper(int k, int i, int jump, bool fl) {
        if(i > k + 1) return 0;
        
        string state = to_string(i) + "," + to_string(jump) + "," + to_string(fl);
        
        if(dp.find(state) != dp.end()) {
            return dp[state];
        }
        
        int ways = (i == k);
        
        if(fl && i > 0) {
            ways = (ways + helper(k, i - 1, jump, false));
        }
        
        if((i + (1ll << jump)) <= k + 1) {
            ways = (ways + helper(k, (i + (1ll << jump)), jump + 1, true));
        }
        
        return dp[state] = ways;
    }
    int waysToReachStair(int k) {
        return helper(k, 1, 0, true);
    }
};