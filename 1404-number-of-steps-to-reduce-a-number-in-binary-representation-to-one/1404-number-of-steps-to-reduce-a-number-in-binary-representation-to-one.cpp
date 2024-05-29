class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.size() != 1) {
            if(s[s.size() - 1] == '1') {
                int idx = -1;
                string res = "1";
                for(int i = s.size() - 1; i >= 0; --i) {
                    if(s[i] == '0') {
                        idx = i;
                        break;
                    } else {
                        res += '0';
                        s[i] = '0';
                    }
                }
                
                if(idx == -1) {
                    s = res;
                } else {
                    s[idx] = '1';
                }
            } else {
                s.pop_back();
            }
            ans++;
        }
        return ans;
    }
};