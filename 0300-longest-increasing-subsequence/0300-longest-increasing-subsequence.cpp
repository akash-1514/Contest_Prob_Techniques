class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        for(int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
            if(it == seq.end()) {
                seq.push_back(nums[i]);
            } else {
                seq[it - seq.begin()] = nums[i];
            }
        }
        return seq.size();
    }
};