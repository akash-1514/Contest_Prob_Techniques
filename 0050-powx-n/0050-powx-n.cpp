class Solution {
public:
    double binExpo(double x, long long n) {
        if(n == 0) return 1.0;
        double res = binExpo(x, n / 2);
        if(n % 2 != 0) return x * res * res;
        return res * res;
    }
    double myPow(double x, int n) {
        if(n < 0) {
            return binExpo((1.0 / x), -((long long)n));
        }
        return binExpo(x, n);
    }
};