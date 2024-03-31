class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int start = -1;
        int mnIdx = -1, mxIdx = -1, mn = 1e9, mx = -1e9;
        long long ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < minK || nums[i] > maxK) {
                start = i;
                mnIdx = -1, mxIdx = -1;
                mn = 1e9, mx = -1e9;
            } else {
                if(nums[i] >= mx) {
                    mx = nums[i];
                    mxIdx = i;
                }
                
                if(nums[i] <= mn) {
                    mn = nums[i];
                    mnIdx = i;
                }
                
                if(mn == minK && mx == maxK) {
                    ans += min(mnIdx, mxIdx) - start;
                }
            }
        }
        return ans;
    }
};