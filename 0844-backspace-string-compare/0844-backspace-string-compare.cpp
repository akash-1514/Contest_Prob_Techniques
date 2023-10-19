class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "", s2 = "";
        for(char &ch : s) {
            if(ch == '#') {
                if(s1.empty()) continue;
                s1.pop_back();
            } else {
                s1 += ch;
            }
        }
        for(char &ch : t) {
            if(ch == '#') {
                if(s2.empty()) continue;
                s2.pop_back();
            } else {
                s2 += ch;
            }
        }
        return s1 == s2;
    }
};