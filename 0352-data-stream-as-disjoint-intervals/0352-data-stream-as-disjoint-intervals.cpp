class SummaryRanges {
public:
    map<int, int>mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int left = value, right = value;
        auto upper = mp.upper_bound(value);
        if(upper != mp.begin()) {
            auto it = upper;
            it--;
            if(it->second >= value) return;
            if(it->second == value - 1) {
                left = it->first;
            }
        }

        if(upper != mp.end()) {
            if(upper->first == value + 1) {
                right = upper->second;
                mp.erase(upper);
            }
        }

        mp[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        for(auto &it : mp) {
            ans.push_back({it.first, it.second});
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