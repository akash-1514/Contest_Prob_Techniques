class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>>vec;
        for(int ele : arr) {
            int x = __builtin_popcount(ele);
            vec.push_back({x, ele});
        }
        sort(vec.begin(), vec.end());
        vector<int>ans;
        for(pair<int, int>&ele : vec) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};