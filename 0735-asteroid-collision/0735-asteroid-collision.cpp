class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i = 0; i < asteroids.size(); ++i) {
            if(st.empty()) {
                st.push(asteroids[i]);
            } else {
                bool fl = true;
                while(!st.empty() && (st.top() > 0 && asteroids[i] < 0)) {
                    if(st.top() == -1 * asteroids[i]) {
                        st.pop();
                        fl = false;
                        break;
                    } else if(st.top() > -1 * asteroids[i]) {
                        fl = false;
                        break;
                    } else {
                        st.pop();
                    }
                }
                if(fl) {
                    st.push(asteroids[i]);
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