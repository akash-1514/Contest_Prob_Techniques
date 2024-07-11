class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<string>st;
        int i = n - 1;
        while(i >= 0) {
            if(s[i] == ')') {
                st.push(")");
                i--;
            } else if(s[i] == '(') {
                string sub = "";
                while(!st.empty() && st.top() != ")") {
                    sub += st.top();
                    st.pop();
                }
                st.pop();
                reverse(sub.begin(), sub.end());
                st.push(sub);
                
                i--;
            } else {
                string sub = "";
                while(i >= 0 && (s[i] >= 'a' && s[i] <= 'z')) {
                    sub += s[i];
                    i--;
                }
                reverse(sub.begin(), sub.end());
                st.push(sub);
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};