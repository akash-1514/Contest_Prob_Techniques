class Solution {
private:
    unordered_map<int, int>mp;
public:
    int convert(string &s) {
        int res = 0;
        for(char ch : s) {
            res = res * 10 + (mp[ch - '0']);
        }
        return res;
    }
    
    static bool cmp(pair<int, int>&a, pair<int, int>&b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i <= 9; ++i) {
            mp[i] = mapping[i];
        }
        
        vector<pair<int, int>>vec;
        for(int i = 0; i < n; ++i) {
            string str = to_string(nums[i]);
            int changed = convert(str);
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