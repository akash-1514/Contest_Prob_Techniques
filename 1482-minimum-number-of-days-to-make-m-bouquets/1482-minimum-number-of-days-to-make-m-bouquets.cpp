class Solution {
public:
    bool pred(vector<int>&arr, int mid, int m, int k) {
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] <= mid) {
                cnt++;
                if(cnt == k) {
                    m--;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return m <= 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(pred(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};