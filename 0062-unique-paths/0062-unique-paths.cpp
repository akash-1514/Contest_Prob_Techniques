class Solution {
public:
    int uniquePaths(int m, int n) {
        int tot = m + n - 2;
        int r = min(m - 1, n - 1);
        double res = 1.0;
        for(int i = 1; i <= r; ++i, tot--) {
            res = (res * tot) / i;
        }
        return (int)res;
    }
};