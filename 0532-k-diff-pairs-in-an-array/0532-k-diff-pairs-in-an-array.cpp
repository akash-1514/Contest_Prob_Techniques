class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; ++i) {
            if(mp[nums[i] - k] > 0) {
                ans++;
                while(i < n - 1 && nums[i] == nums[i + 1]) i++;
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};