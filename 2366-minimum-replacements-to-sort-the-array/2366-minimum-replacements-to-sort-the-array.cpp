class Solution {
public:
    long long minimumReplacement(vector<int>& arr) {
        int n = arr.size(), mn = arr[n - 1];
        long long ans = 0;
        for(int i = n - 2; i >= 0; --i) {
            if(arr[i] > mn) {
                int ele = ceil(1.0 * arr[i] / mn);  
                ans += (ele - 1);
                mn = arr[i] / ele;
            } else {
                mn = min(mn, arr[i]);
            }
        }
        return ans;
    }
};