class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U');
    }
    bool halvesAreAlike(string s) {
        int cnt = 0, n = s.size();
        for(int i = 0; i < n; ++i) {
            if(i < n / 2) {
                if(isVowel(s[i])) cnt++;
            } else {
                if(isVowel(s[i])) cnt--;
            }
        }
        return cnt == 0;
    }
};