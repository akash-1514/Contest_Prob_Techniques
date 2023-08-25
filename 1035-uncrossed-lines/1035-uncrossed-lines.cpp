class Solution {
public:
    int dp[501][501];
    int helper(vector<int>&arr1, vector<int>&arr2, int idx1, int idx2) {
        if(idx1 >= arr1.size() || idx2 >= arr2.size()) return 0;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(arr1[idx1] == arr2[idx2]) {
            return dp[idx1][idx2] = 1 + helper(arr1, arr2, idx1 + 1, idx2 + 1);
        } else {
            return dp[idx1][idx2] = max(helper(arr1, arr2, idx1 + 1, idx2), helper(arr1, arr2, idx1, idx2 + 1));
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return helper(nums1, nums2, 0, 0);
    }
};