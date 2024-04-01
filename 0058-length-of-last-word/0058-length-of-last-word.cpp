class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        bool fl = false;
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == ' ') {
                if(fl) break;
            } else {
                fl = true;
                cnt++;
            }
        }
        return cnt;
    }
};