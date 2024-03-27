class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        if(k == 0) return 0;
        int prod = 1, n = arr.size(), ans = 0, i = 0;
        for(int j = 0; j < n; ++j) {
            prod *= arr[j];
            while(i <= j && prod >= k) {
                prod /= arr[i++];
            }
            ans += (j - i + 1);
        }
        return ans;
    }
};