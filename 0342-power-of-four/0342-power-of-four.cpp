class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;
        return !(n & ((long long)n - 1)) && ((long long)log2(n) % 2 == 0);
    }
};