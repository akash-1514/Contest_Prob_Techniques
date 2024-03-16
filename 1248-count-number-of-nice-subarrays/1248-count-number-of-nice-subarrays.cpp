class Solution {
public:
    int atmost(vector<int>&nums, int k)
    {
        int windowStart = 0;
        int ans = 0;
        
        for(int windowEnd = 0; windowEnd < nums.size(); ++windowEnd)
        {
            if(nums[windowEnd] % 2 != 0) k--;
            
            while(k < 0)
            {
                if(nums[windowStart] % 2 != 0) k++;
                windowStart++;
            }
            
            ans += (windowEnd - windowStart + 1);
        }
        
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        // return atmost(nums, k) - atmost(nums, k - 1);
        unordered_map<int, int>mp;
        mp[0] = 1;
        int ans = 0, cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            cnt += (nums[i] % 2 != 0);
            ans += mp[cnt - k];
            mp[cnt]++;
        }
        return ans;
    }
};