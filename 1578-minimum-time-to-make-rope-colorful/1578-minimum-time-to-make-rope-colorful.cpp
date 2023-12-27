class Solution {
public:
    int dp[100001][27];
    int helper(string &color, vector<int>&neededTime, int idx, int prev) {
        if(idx >= color.size()) return 0;
        
        if(dp[idx][prev] != -1) return dp[idx][prev];
        
        int ans = 0;
        if(color[idx] - 'a' != prev) {
            ans = max(ans, neededTime[idx] + helper(color, neededTime, idx + 1, color[idx] - 'a'));
        }
        
        ans = max(ans, helper(color, neededTime, idx + 1, prev));
        return dp[idx][prev] = ans;
    }
    int minCost(string colors, vector<int>& neededTime) {
        memset(dp, -1, sizeof(dp));
        int res = helper(colors, neededTime, 0, 26);
        int tot = 0;
        for(int ele : neededTime) tot += ele;
        return tot - res;
    }
};