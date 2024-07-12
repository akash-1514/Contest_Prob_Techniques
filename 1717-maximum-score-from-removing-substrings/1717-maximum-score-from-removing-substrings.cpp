class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x > y) {
            stack<int>st;
            int idx = 0;
            int ans = 0;
            for(char ch : s) {
                if(ch == 'b') {
                    if(!st.empty() && s[st.top()] == 'a') {
                        s[st.top()] = '.';
                        s[idx] = '.';
                        ans += x;
                        st.pop();
                    } else {
                        st.push(idx);
                    }
                } else {
                    st.push(idx);
                }
                idx++;
            }
            
            stack<int>st2;
            idx = 0;
            for(char ch: s) {
                if(ch == '.') {
                    idx++;
                    continue;
                }
                if(ch == 'a') {
                    if(!st2.empty() && s[st2.top()] == 'b') {
                        ans += y;
                        st2.pop();
                    } else {
                        st2.push(idx);
                    }
                } else {
                    st2.push(idx);
                }
                idx++;
            }
            
            return ans;
        } else {
            int ans = 0;
            stack<int>st;
            int idx = 0;
            for(char ch : s) {
                if(ch == 'a') {
                    if(!st.empty() && s[st.top()] == 'b') {
                        s[st.top()] = '.';
                        s[idx] = '.';
                        ans += y;
                        st.pop();
                    } else {
                        st.push(idx);
                    }
                } else {
                    st.push(idx);
                }
                idx++;
            }
            
            stack<int>st2;
            idx = 0;
            for(char ch: s) {
                if(ch == '.') {
                    idx++;
                    continue;
                }
                if(ch == 'b') {
                    if(!st2.empty() && s[st2.top()] == 'a') {
                        ans += x;
                        st2.pop();
                    } else {
                        st2.push(idx);
                    }
                } else {
                    st2.push(idx);
                }
                idx++;
            }
            
            return ans;
        }
    }
};