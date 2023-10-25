class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) {
            return 0;
        }
        int recAns = kthGrammar(n - 1, ceil(1.0 * k / 2));
        if(k % 2 != 0) {
            return recAns;
        } else {
            return !recAns;
        }
    }
};