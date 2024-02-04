class Solution {
public:
    string minWindow(string s, string t) {
        int start = -1, end = -1, n = s.size();   
        int mn = 1e9;
        unordered_map<char, int>smp, tmp;
        for(char ch : t) tmp[ch]++;
        
        int cnt = 0, i = 0;
        for(int j = 0; j < n; ++j) {
            smp[s[j]]++;
            if(tmp.find(s[j]) != tmp.end() && smp[s[j]] == tmp[s[j]]) {
                cnt++;
            }
            
            while(cnt == tmp.size()) {
                if(j - i + 1 < mn) {
                    mn = j - i + 1;
                    start = i, end = j;
                }
                if(tmp.find(s[i]) != tmp.end() && smp[s[i]] == tmp[s[i]]) {
                    cnt--;
                }    
                smp[s[i]]--;
                i++;
            }
        }
        
        if(start == -1) return "";
        string res = s.substr(start, end - start + 1);
        return res;
    }
};