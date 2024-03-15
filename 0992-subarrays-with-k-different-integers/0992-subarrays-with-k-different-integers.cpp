class Solution {
public:
    int atmostK(vector<int>&nums, int k) {
        int ans = 0;
        unordered_map<int, int>mp;
        
        int i = 0;
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
        int len1 = atmostK(nums, k);
        int len2 = atmostK(nums, k - 1);
        return len1 - len2;
    }
};