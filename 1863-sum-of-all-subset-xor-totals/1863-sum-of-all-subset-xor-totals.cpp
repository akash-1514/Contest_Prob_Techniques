class Solution {
public:
    void helper(vector<int>&nums, int idx, int &ans, int res) {
        if(idx >= nums.size()) {
            ans += res;
            return;
        }
        
        helper(nums, idx + 1, ans, res ^ nums[idx]);
        helper(nums, idx + 1, ans, res);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        helper(nums, 0, ans, 0);
        return ans;
    }
};