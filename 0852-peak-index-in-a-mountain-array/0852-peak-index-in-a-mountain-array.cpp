class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(arr[mid] > arr[mid + 1]) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};