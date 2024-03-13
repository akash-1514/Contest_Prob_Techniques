class Solution {
public:
    int pivotInteger(int n) {
        long long res = (n * 1ll * (n + 1)) / 2, s = sqrt(res);
        if(s * s == res) {
            return s;
        } else {
            return -1;
        }
    }
};