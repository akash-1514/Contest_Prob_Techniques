class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int res = *max_element(arr.begin(), arr.end()), n = arr.size();
        if(k >= n - 1) {
            return res;
        }
        
        int mx = 0, cnt = 0, prev = -1;
        for(int i = 0; i < n; ++i) {
            mx = max(mx, arr[i]);
            if(prev == mx) {
                cnt++;
                if(cnt >= k) return mx;
            } else {
                if(prev == -1) {
                    cnt = 0;
                } else {
                    cnt = 1;
                    if(cnt >= k) return mx;
                }
                prev = mx;
            }
        }
        return res;
    }
};