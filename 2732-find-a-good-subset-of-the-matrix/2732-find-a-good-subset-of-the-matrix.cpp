class Solution {
public:
    bool valid(int curr, int prev) {
        for(int j = 0; j < 32; ++j) {
            if((curr & (1 << j)) != 0 && (prev & (1 << j)) != 0) {
                return false;
            }
        }
        return true;
    }
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_map<int, int>mp;
        vector<int> vec;
        for(int i = 0; i < grid.size(); ++i) {
            int num = 0;
            for(int j = grid[0].size() - 1; j >= 0; --j) {
                if(grid[i][j] == 0) continue;
                num |= (1 << j);
            }
            vec.push_back(num);
        }
        
        for(int i = 0; i < vec.size(); ++i) {
            if(vec[i] == 0) return {i};
            for(int j = 0; j < (1 << grid[0].size()); ++j) {
                if(valid(vec[i], j)) {
                    if(mp.find(j) != mp.end()) {
                        return {mp[j], i};
                    }
                }
            }
            mp[vec[i]] = i;
        }
        return {};
    }
};