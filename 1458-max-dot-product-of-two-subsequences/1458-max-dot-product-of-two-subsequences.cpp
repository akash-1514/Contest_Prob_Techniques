class Solution {
public:
    int dp[501][501][2];
    int helper(vector<int>&arr1, vector<int>&arr2, int i, int j, bool empty) {
        if(i == arr1.size() || j == arr2.size()) {
            if(empty == false) {
                return 0;
            } else {
                return -1e9;
            }
        }
        
        if(dp[i][j][empty] != -1) return dp[i][j][empty];
        
        int pick = arr1[i] * arr2[j] + helper(arr1, arr2, i + 1, j + 1, false);
        int notPick = max(helper(arr1, arr2, i + 1, j, empty), helper(arr1, arr2, i, j + 1, empty));
        
        
        return dp[i][j][empty] = max(pick, notPick);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return helper(nums1, nums2, 0, 0, true);
    }
};