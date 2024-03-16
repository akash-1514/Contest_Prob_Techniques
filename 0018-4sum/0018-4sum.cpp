class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                long long reqSum = target - (1ll * nums[i] + nums[j]);
                int start = j + 1, end = n - 1;
                while(start < end) {
                    long long currSum = 1ll * nums[start] + nums[end];
                    if(currSum == reqSum) {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        start++, end--;
                        while(start < end && nums[start] == nums[start - 1]) start++;
                        while(start < end && nums[end] == nums[end + 1]) end--;
                    } else if(currSum > reqSum) {
                        end--; 
                    } else {
                        start++;
                    }
                }
                while(j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            while(i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};