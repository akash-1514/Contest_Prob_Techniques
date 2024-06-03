class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int>prev;
        int mn = 1e9;
        for(int i = 0; i < n; ++i) {
            unordered_set<int> curr = {nums[i]};
            mn = min(mn, abs(k - nums[i]));
            for(auto &it : prev) {
                curr.insert(nums[i] & it);
                mn = min(mn, abs(k - (nums[i] & it)));
            }
            prev = curr;
        }
        return mn;
    }
};