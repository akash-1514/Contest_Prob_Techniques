class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<char>st;
        for(auto &s : logs) {
            string sub = s.substr(0, 2);
            if(sub == "./") continue;
            if(sub == "..") {
                if(!st.empty()) st.pop();
            } else {
                st.push('f');
            }
        }
        
        return st.size();
    }
};