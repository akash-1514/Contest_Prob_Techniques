class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int res = *max_element(arr.begin(), arr.end()), n = arr.size();
        if(k >= n - 1) {
            return res;
        }
        
        int mx = arr[0], cnt = 0, prev = arr[0];
        for(int i = 1; i < n; ++i) {
            mx = max(mx, arr[i]);
            if(prev == mx) {
                cnt++;
                if(cnt >= k) return mx;
            } else {
                cnt = 1;
                if(cnt >= k) return mx;
                prev = mx;
            }
        }
        return res;
    }
};