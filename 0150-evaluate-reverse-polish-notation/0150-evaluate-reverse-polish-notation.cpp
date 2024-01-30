class Solution {
public:
    bool isArithmetic(string &s) {
        return (s == "+" || s == "-" || s == "/" || s == "*");
    }
    int evalRPN(vector<string>& token) {
        int n = token.size();
        stack<int>st;
        for(int i = 0; i < n; ++i) {
            if(isArithmetic(token[i])) {
                int tp1 = st.top(); st.pop();
                int tp2 = st.top(); st.pop();
                
                if(token[i] == "+") {
                    st.push(tp1 + tp2);
                } else if(token[i] == "*") {
                    st.push(tp1 * tp2);
                } else if(token[i] == "/") {
                    st.push(tp2 / tp1);
                } else {
                    st.push(tp2 - tp1);
                }
            } else {
                int x = stoi(token[i]);
                st.push(x);
            }
        }
        
        return st.top();
    }
};