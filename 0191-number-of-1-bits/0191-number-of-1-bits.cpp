class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = __builtin_popcountll(n);
        return bits;
    }
};