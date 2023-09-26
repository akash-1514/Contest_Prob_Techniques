class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i = 0; i < num.size(); ++i) {
            while(!st.empty() && st.top() > (num[i] - '0') && k > 0) {
                st.pop();
                k--;
            }
            
            if(st.empty()) {
                if((num[i] - '0') != 0) {
                    st.push(num[i] - '0');
                }
            } else {
                st.push(num[i] - '0');
            }
        }
        
        while(!st.empty() && k > 0) {
            k--;
            st.pop();
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += (st.top() + '0');
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans.empty() ? "0" : ans;
    }
};