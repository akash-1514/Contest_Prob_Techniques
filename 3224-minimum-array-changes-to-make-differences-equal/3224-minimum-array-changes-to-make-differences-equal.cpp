class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int>mp;
        
        vector<int> diff(k + 3, 0);
        
        for(int i = 0; i < n / 2; ++i) {
            int a = nums[i], b = nums[n - i - 1];
            mp[abs(a - b)]++;
            
            int l = min((nums[i] - min(k, nums[i])), (nums[n - i - 1] - min(k, nums[n - i - 1])));
            int r = max({nums[i], nums[n - i - 1], abs(nums[i] - k), abs(nums[n - i - 1] - k)});
            
            // cout << l << " " << r << "\n";
            
            diff[l]++;
            diff[r + 1]--;
        }
        
        for(int i = 1; i <= k; ++i) {
            diff[i] += diff[i - 1];
        }
        
        int ans = 1e9;
        for(int i = 0; i <= k; ++i) {
            int res = diff[i] - mp[i] + ((n / 2) - diff[i]) * 2;
            ans = min(ans, res);
        }
        
        return ans;
    }
};