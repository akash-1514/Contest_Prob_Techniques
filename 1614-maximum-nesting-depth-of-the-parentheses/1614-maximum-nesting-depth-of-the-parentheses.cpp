class Solution {
public:
    int maxDepth(string s) {
        int mx = 0, o = 0;
        for(char ch : s) {
            if(ch == '(') {
                o++;
            } else if(ch == ')') {
                o--;
            }
            mx = max(mx, o);
        }
        return mx;
    }
};