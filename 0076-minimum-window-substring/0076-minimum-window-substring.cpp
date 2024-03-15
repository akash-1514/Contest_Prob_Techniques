class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_freq, t_freq;
        for(char ch : t) t_freq[ch]++;
        
        int ws = 0;
        int ansStart = -1, ansEnd = -1, mn = 1e9;
        int cnt = 0;
        for(int we = 0; we < s.size(); ++we) {
            s_freq[s[we]]++;
            if(t_freq.find(s[we]) != t_freq.end() && s_freq[s[we]] == t_freq[s[we]]) cnt++;
            while(cnt == t_freq.size()) {
                // try to shrink the window
                if(we - ws + 1 < mn) {
                    mn = we - ws + 1;
                    ansStart = ws, ansEnd = we;
                }
                if(t_freq.find(s[ws]) != t_freq.end() && s_freq[s[ws]] == t_freq[s[ws]]) {
                    cnt--;
                }
                
                s_freq[s[ws]]--;
                ws++;
            }
        }
        
        if(ansStart == -1) return "";
        return s.substr(ansStart, ansEnd - ansStart + 1);
    }
};