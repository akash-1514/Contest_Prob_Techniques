class Solution {
public:
    int helper(string &s, int idx, int n) {
        if(n == 0) return 1;
        if(idx == s.size()) return 0;
        
        int cnt = 0;
        
        cnt += helper(s, idx, n - 1);
        
        cnt += helper(s, idx + 1, n);
        
        return cnt;
    }
    int countVowelStrings(int n) {
        string s = "aeiou";
        return helper(s, 0, n);
    }
};