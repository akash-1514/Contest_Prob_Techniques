class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int>vec;
        vector<vector<int>>ans;
        for(auto &it : st) vec.push_back(it);
        for(int i = 0; i < vec.size();) {
            int left = vec[i], right = vec[i];
            while(i < vec.size() && right == vec[i]) {
                i++, right++;
            }
            ans.push_back({left, right - 1});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */