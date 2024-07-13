class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = healths.size();
        vector<vector<int>> vec;
        for(int i = 0; i < n; ++i) {
            int dir = (directions[i] == 'L') ? 0 : 1;
            vec.push_back({positions[i], healths[i], dir});
        }
        sort(vec.begin(), vec.end());
        stack<int>st;
        for(int i = 0; i < n; ++i) {
            if(vec[i][2] == 1) {
                st.push(i);
            } else {
                
                bool fl = false;
                while(!st.empty() && vec[st.top()][2] == 1) {
                    if(vec[st.top()][1] > vec[i][1]) {
                        if(--vec[st.top()][1] == 0) st.pop();
                        fl = true;
                        break;
                    } else if(vec[st.top()][1] == vec[i][1]) {
                        st.pop();
                        fl = true;
                        break;
                    } else {
                        st.pop();
                        if(--vec[i][1] == 0) {
                            fl = true;
                            break;
                        }
                    }
                }
                
                if(!fl) {
                    st.push(i);
                }
            }
        }
        
        vector<int>ans;
        unordered_map<int, int>mp;
        while(!st.empty()) {
            mp[vec[st.top()][0]] = vec[st.top()][1];
            st.pop();
        }
        
        for(int i = 0; i < positions.size(); ++i) {
            if(mp.find(positions[i]) == mp.end()) continue;
            ans.push_back(mp[positions[i]]);
        }
        
        return ans;
    }
};