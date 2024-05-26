class Solution {
    int mod = (int)1e9 + 7;
    public int maximumSumSubsequence(int[] a, int[][] q) {
        int n = a.length;
        int m = q.length;
        int ans = 0;
        for(int i = 0; i < m; ++i){
            int pos = q[i][0];
            int val = q[i][1];
            a[pos] = val;
            ans =  (ans % mod + maxAdj(a, n)%mod)%mod;
        }
        return ans;
    }
    public int maxAdj(int[] a, int n){
        if(n == 1) return Math.max(0, a[0]);
        int prev2 = Math.max(0, a[0]);
        int prev1 = prev1 = Math.max(0, Math.max(a[0], a[1]));
        int cur = 0;
        for(int i = 2; i < n; ++i){
            cur = Math.max(0, Math.max((prev2 + a[i])%mod, prev1));
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
}