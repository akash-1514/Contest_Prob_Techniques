class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1, n = nums.size();
        
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(nums[mid] >= target) {
                if(nums[mid] == target) {
                    first = mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(nums[mid] <= target) {
                if(nums[mid] == target) {
                    last = mid;
                }
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return {first, last};
    }
};