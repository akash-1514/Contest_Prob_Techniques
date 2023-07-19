class Solution {
public:
    bool pred(vector<int>&nums, int threshold, int mid) {
        int sum = 0;
        for(int ele : nums) {
            sum += ceil((ele * 1.0) / mid);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1e9;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(pred(nums, threshold, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};