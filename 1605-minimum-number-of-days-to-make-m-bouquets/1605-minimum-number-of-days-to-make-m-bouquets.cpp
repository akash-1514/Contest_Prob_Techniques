class Solution {
public:
    bool pred(vector<int>&arr, int m, int k, int days) {
        int cnt = 0, b = 0;
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] <= days) {
                cnt++;
                if(cnt % k == 0) b++;
            } else {
                cnt = 0;
            }
        }
        return b >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = 0, ans = -1;
        for(int ele : bloomDay) high = max(high, ele);
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(pred(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};