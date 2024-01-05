static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>lis;
        for(int i = 0; i < n; ++i) {
            if(lis.empty()) {
                lis.push_back(nums[i]);
            } else {
                if(nums[i] > lis.back()) {
                    lis.push_back(nums[i]);
                } else {
                    auto idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                    lis[idx] = nums[i];
                }
            }
        }
        return lis.size();
    }
};