class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char ch : num) {
            if(st.empty()) {
                if(ch != '0') st.push(ch);
            } else {
                while(!st.empty() && ch - '0' < st.top() - '0' && k-- > 0) {
                    st.pop();
                }
                if(st.empty()) {
                    if(ch != '0') st.push(ch);
                } else {
                    st.push(ch);
                }
            }
        }
        while(!st.empty() && k-- > 0) st.pop();
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};