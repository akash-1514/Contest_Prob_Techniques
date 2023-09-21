class Solution {
public:
    int pred(vector<int>&nums, int mid) {
        int cnt = 0, i = 0;
        for(int j = 0; j < nums.size(); ++j) {
            while(nums[j] - nums[i] > mid) {
                i++;
            }
            cnt += (j - i);
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[nums.size() - 1] - nums[0], ans = 0;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(pred(nums, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};