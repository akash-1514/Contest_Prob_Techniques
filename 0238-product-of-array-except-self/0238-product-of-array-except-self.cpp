#define ll long long
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 1);
        int pre = 1, suff = 1;
        for(int i = 0; i < n; ++i) {
            ans[i] *= pre;
            ans[n - i - 1] *= suff;
            pre *= nums[i];
            suff *= nums[n - i - 1];
        }
        return ans;
    }
};