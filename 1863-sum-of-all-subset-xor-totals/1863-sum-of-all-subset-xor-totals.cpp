class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < (1 << n); ++i) {
            int res = 0;
            for(int j = 0; j < 32; ++j) {
                if((i & (1 << j)) != 0) {
                    res ^= nums[j];
                }
            }
            ans += res;
        }
        return ans;
    }
};