class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto &ast : asteroids) {
            if(st.empty()) {
                st.push(ast);
            } else {
                bool fl = true;
                while(!st.empty() && (st.top() > 0 && ast < 0)) {
                    if(st.top() == -1 * ast) {
                        st.pop();
                        fl = false;
                        break;
                    } else if(st.top() > -1 * ast) {
                        fl = false;
                        break;
                    } else {
                        st.pop();
                    }
                }
                if(fl) {
                    st.push(ast);
                }
            }
        }
        
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};