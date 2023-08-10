class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, ans = 1e9;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(arr[mid] == arr[low] && arr[mid] == arr[high]) {
                ans = min(ans, arr[mid]);
                low++, high--;
            } else if(arr[low] <= arr[mid] && arr[mid] <= arr[high]) {
                ans = min(ans, arr[low]);
                break;
            } else if(arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]);
                low = mid + 1;
            } else {
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};