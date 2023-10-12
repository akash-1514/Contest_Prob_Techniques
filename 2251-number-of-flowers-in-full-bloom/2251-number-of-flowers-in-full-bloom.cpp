class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int>mp;
        for(auto &r : flowers) mp[r[0]]++, mp[r[1] + 1]--;
        int sum = 0;
        for(auto &it : mp) {
            sum += it.second;
            it.second = sum;
        }
        
        vector<int>ans;
        for(int &ele : people) {
            auto it = mp.upper_bound(ele);
            if(it == mp.begin()) {
                ans.push_back(0);
            } else {
                ans.push_back((--it)->second);
            }
        }
        return ans;
    }
};