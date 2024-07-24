class Solution {
public:
    int convert(string &s, vector<int>&mapping) {
        int res = 0;
        for(char ch : s) {
            res = res * 10 + (mapping[ch - '0']);
        }
        return res;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>>vec;
        for(int i = 0; i < n; ++i) {
            string str = to_string(nums[i]);
            int changed = convert(str, mapping);
            vec.push_back({changed, i});
        }
        
        sort(vec.begin(), vec.end(), [&](pair<int, int>&a, pair<int, int>&b) {
            if(a.first == b.first) {
                return a.second < b.second;
            } 
            return a.first < b.first;
        });
        
        vector<int>ans;
        for(int i = 0; i < n; ++i) {
            ans.push_back(nums[vec[i].second]);
        }
        return ans;
    }
};