class Solution {
public:
    const long long mod = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long>dp;
        dp[arr[0]] = 1;
        int ans = 1;
        for(int i = 1; i < n; ++i) {
            int cnt = 1;
            for(int j = 0; j < i; ++j) {
                if(arr[i] % arr[j] == 0) {
                    cnt = (cnt + dp[arr[j]] % mod * dp[arr[i] / arr[j]] % mod) % mod;
                }
            }
            dp[arr[i]] = cnt;
            ans = (ans + dp[arr[i]]) % mod;
        }
        return ans;
    }
};