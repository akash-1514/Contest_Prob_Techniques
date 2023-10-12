/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray &arr, int low, int high, int target, bool fl) {
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(arr.get(mid) == target) return mid;
            else if(arr.get(mid) > target) {
                if(fl) high = mid - 1;
                else low = mid + 1;
            } else {
                if(fl) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int low = 1, high =  n - 2, ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            int curr = arr.get(mid), prev = arr.get(mid - 1), next = arr.get(mid + 1);
            if(curr > prev && curr > next) {
                ans = mid;
                break;
            } else if(curr < prev) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        int res = binarySearch(arr, 0, ans, target, true);
        if(res != -1) return res;
        res = binarySearch(arr, ans + 1, n - 1, target, false);
        return res;
    }
};