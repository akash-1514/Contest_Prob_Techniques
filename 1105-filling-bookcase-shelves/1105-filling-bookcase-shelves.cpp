class Solution {
public:
    int dp[1001];
    int helper(vector<vector<int>>&arr, int idx, int shelfWidth) {
        if(idx >= arr.size()) {
            return 0;
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        int sum = 0, mx = 0, ans = 1e9;
        for(int i = idx; i < arr.size(); ++i) {
            sum += arr[i][0];
            mx = max(mx, arr[i][1]);
            if(sum <= shelfWidth) {
                ans = min(ans, mx + helper(arr, i + 1, shelfWidth));
            }
        }
        
        return dp[idx] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        return helper(books, 0, shelfWidth);
    }
};