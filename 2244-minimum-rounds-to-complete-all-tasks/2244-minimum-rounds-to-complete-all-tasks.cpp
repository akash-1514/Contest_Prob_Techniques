class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int>mp;
        for(int ele : tasks) mp[ele]++;
        int ans = 0;
        for(auto &it : mp) {
            if(it.second == 1) return -1;
            ans += (it.second / 3);
            if(it.second % 3 != 0) ans++;
        }
        
        return ans;
    }
};