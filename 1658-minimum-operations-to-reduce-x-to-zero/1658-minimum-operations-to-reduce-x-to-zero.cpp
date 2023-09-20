class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totSum = 0, n = nums.size(), sum = 0, idx = 0;
        unordered_map<int, int>mp;
        for(int ele : nums) {
            sum += ele;
            mp[sum] = idx++;
            totSum += ele;
        }
        
        if(x > totSum) return -1;
        
        int tar = totSum - x, mx = INT_MIN;
        mp[0] = -1;
        sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            if(mp.find(sum - tar) != mp.end()) {
                mx = max(mx, i - mp[sum - tar]);
            }
        }
        if(mx == INT_MIN) return -1;
        return nums.size() - mx;
    }
};