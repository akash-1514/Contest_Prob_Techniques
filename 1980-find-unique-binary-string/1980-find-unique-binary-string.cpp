class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string, int>mp;
        for(auto &s : nums) mp[s]++;
        int n = nums.size();
        for(int i = 0; i < (1 << n); ++i) {
            string s;
            for(int j = 0; j < n; ++j) {
                if((i & (1 << j)) != 0) {
                    s.push_back('1');
                } else {
                    s.push_back('0');
                }
            }
            reverse(s.begin(), s.end());
            if(mp.find(s) == mp.end()) {
                return s;
            }
        }
        return "";
    }
};