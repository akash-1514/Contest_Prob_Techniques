class Solution {
public:
    int atmostk(vector<int>&nums, int k) {
        int ans = 0, i = 0;
        unordered_map<int, int>mp;
        for(int j = 0; j < nums.size(); ++j) {
            mp[nums[j]]++;
            while(mp.size() > k) {
                if(--mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums, k) - atmostk(nums, k - 1);
    }
};