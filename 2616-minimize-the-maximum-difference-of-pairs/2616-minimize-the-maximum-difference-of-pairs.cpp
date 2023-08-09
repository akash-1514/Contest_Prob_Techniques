class Solution {
public: 
    bool pred(vector<int>&nums, int p, int mid) {
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(abs(nums[i] - nums[i + 1]) <= mid) {
                i++;
                cnt++;
            }
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = 1e9;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(pred(nums, p, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};