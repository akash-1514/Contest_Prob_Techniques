class Solution {
public:
    int minOperations(string s) {
        int op1 = 0, op2 = 0, prev2 = 0, prev1 = 1;
        for(char ch : s) {
            if(ch == '0') {
                if(prev1 == 0) {
                    op1++, prev1 = 1;
                } else {
                    prev1 = ch - '0';
                }
                if(prev2 == 0) {
                    op2++, prev2 = 1;
                } else {
                    prev2 = ch - '0';
                }
            } else {
                if(prev1 == 1) {
                    op1++, prev1 = 0;
                } else {
                    prev1 = ch - '0';
                }
                if(prev2 == 1) {
                    op2++, prev2 = 0;
                } else {
                    prev2 = ch - '0';
                }
            }
        }
        return min(op1, op2);
    }
};