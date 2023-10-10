class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for(int i = 0; i < nums.size(); ++i) {
            if(sub.size() == 0 || nums[i] > sub[sub.size() - 1]) {
                sub.push_back(nums[i]);
            } else {
                auto idx = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
                sub[idx] = nums[i];
            }
        }
        return sub.size();
    }
};