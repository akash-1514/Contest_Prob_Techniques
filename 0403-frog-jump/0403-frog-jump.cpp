class Solution {
public:
    unordered_map<int, int>mp;
    int dp[2001][2001];
    bool helper(vector<int>&arr, int idx, int lastJump) {
        if(idx == arr.size() - 1) return true;
        
        if(dp[idx][lastJump] != -1) return dp[idx][lastJump];
        
        for(int i = lastJump - 1; i <= lastJump + 1; ++i) {
            if(i == 0) continue;
            if(mp.find(arr[idx] + i) != mp.end()) {
                if(helper(arr, mp[arr[idx] + i], i)) return true;
            }
        }
        return dp[idx][lastJump] = false;
    }
    bool canCross(vector<int>& stones) {
        if(stones[0] + 1 != stones[1]) return false;
        int idx = 0;
        for(int ele : stones) mp[ele] = idx++;
        memset(dp, -1, sizeof(dp));
        return helper(stones, 1, 1);
    }
};