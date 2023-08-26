class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), mx = 1, cnt = 1, prev = arr[0];
        bool inc = false;
        for(int i = 1; i < n; ++i) {
            if(cnt == 1) {
                if(arr[i] > prev) {
                    inc = true;
                    cnt++;
                } else if(arr[i] < prev) {
                    inc = false;
                    cnt++;
                } else {
                    cnt = 1;
                }
                prev = arr[i];
                mx = max(mx, cnt);
            } else {
                if(inc) {
                    if(arr[i] < prev) {
                        cnt++;
                        prev = arr[i];
                        inc = false;
                    } else if(arr[i] > prev) {
                        cnt = 2;
                        prev = arr[i];
                        inc = true;
                    } else {
                        cnt = 1;
                        prev = arr[i];
                    }
                    mx = max(mx, cnt);
                } else {
                    if(arr[i] > prev) {
                        cnt++;
                        prev = arr[i];
                        inc = true;
                    } else if(arr[i] < prev) {
                        cnt = 2;
                        prev = arr[i];
                        inc = false;
                    } else {
                        cnt = 1;
                        prev = arr[i];
                    }
                    mx = max(mx, cnt);
                }
            }
        }
        return mx;
    }
};