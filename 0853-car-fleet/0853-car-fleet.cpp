class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; ++i) {
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.begin(), vec.end());
        stack<double>st;
        for(int i = 0; i < n; ++i) {
            double time = (1.0 * (target - vec[i].first)) / vec[i].second;
            while(!st.empty() && st.top() <= time) {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};