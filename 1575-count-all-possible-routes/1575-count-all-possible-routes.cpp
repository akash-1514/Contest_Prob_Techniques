class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][201];
    int helper(vector<int>&arr, int idx, int finish, int fuel) {
        if(dp[idx][fuel] != -1) return dp[idx][fuel];
        int ways = (idx == finish) ? 1 : 0;
        for(int i = 0; i < arr.size(); ++i) {
            if(i == idx) continue;
            if(fuel - abs(arr[idx] - arr[i]) >= 0) {
                ways = (ways + helper(arr, i, finish, fuel - abs(arr[idx] - arr[i]))) % mod;
            }
        }
        return dp[idx][fuel] = ways;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        return helper(locations, start, finish, fuel);
    }
};