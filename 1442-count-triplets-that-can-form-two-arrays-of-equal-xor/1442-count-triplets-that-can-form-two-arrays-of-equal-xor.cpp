class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        prefix[0] = 0;
        for(int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int k = i + 1; k <= n; ++k) {
                if(prefix[i] == prefix[k]) {
                    ans += (k - i - 1);
                }
            }
        }
        return ans;
    }
};