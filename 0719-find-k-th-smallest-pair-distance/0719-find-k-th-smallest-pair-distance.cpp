class Solution {
public:
    int pred(vector<int>&nums, int k, int mid) {
        int cnt = 0, i = 0;
        for(int j = 0; j < nums.size(); ++j) {
            while(nums[j] - nums[i] > mid) {
                i++;
            }
            cnt += (j - i);
        }
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 1e9, high = nums[nums.size() - 1] - nums[0];
        for(int i = 0; i < nums.size() - 1; ++i) {
            low = min(low, nums[i + 1] - nums[i]);
        }
        
        while(low < high) {
            int mid = (low + high) >> 1;
            if(pred(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};