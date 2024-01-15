class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int ele : nums) {
            mp[ele % space]++;
        }
        int mx = 0, ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int mod = nums[i] % space;
            if(mp[mod] > mx) {
                mx = mp[mod];
                ans = nums[i];
            } else if(mp[mod] == mx) {
                ans = min(ans, nums[i]);
            }
        }
        return ans;
    }
};