class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), totSum = 0;
        
        for(int ele : nums) {
            totSum += ele;
        }
        
        if(x > totSum) return -1;
        
        unordered_map<int, int>mp;
        int target = totSum - x, sum = 0, mx = INT_MIN;
        mp[0] = -1;
        // extra condition we missed
        if(target == 0) return n;
        
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            if(mp.find(sum - target) != mp.end()) {
                mx = max(mx, i - mp[sum - target]);
            }
            mp[sum] = i;
        }
        
        if(mx == INT_MIN) return -1;
        return n - mx;
    }
};