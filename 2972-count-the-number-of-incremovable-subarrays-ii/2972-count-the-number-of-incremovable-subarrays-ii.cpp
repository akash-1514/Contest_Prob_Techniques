class Solution {
public:
    int binarySearch(vector<int>&nums, vector<int> &suffix, int l, int h, int ele) {
        int low = l, high = h;
        int ans = nums.size();
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(suffix[mid] == 1) {
                if(nums[mid] > ele) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n, 0);
        suffix[n - 1] = 1;
        int prev = nums[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            if(nums[i] >= prev) break;
            suffix[i] = 1;
            prev = nums[i];
        }
        
        prev = 0;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            int idx = binarySearch(nums, suffix, i, n - 1, prev);
            ans += ((n - idx) + (idx != i));
            if(nums[i] <= prev) {
                break;
            }
            prev = nums[i];
        }
        return ans;
    }
};