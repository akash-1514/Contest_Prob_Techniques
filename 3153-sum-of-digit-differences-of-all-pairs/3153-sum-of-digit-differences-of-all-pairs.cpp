class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> pre(10, vector<int>(10, 0));
        long long ans = 0;
        for(int i = nums.size() - 1; i >= 0; --i) {
            string str = to_string(nums[i]);
            for(int k = 0; k < str.size(); ++k) {
                for(int j = 0; j < 10; ++j) {
                    if((str[k] - '0') == j) continue;
                    ans += pre[k][j];
                }
            }
            
            for(int k = 0; k < str.size(); ++k) {
                pre[k][str[k] - '0']++;
            }
        }
        return ans;
    }
};