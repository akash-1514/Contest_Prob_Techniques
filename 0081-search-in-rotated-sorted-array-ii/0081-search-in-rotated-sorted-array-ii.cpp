class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(arr[mid] == target) {
                return true;
            } else if(arr[mid] == arr[low] && arr[mid] == arr[high]) {
                low++;
            } else if(arr[low] <= arr[mid]) {
                if(target >= arr[low] && target <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if(target >= arr[mid] && target <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};