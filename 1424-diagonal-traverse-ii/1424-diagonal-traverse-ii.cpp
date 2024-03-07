class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        
        unordered_map<int, vector<int>>mp;
        for(int i = n - 1; i >= 0; --i) {
            int m = nums[i].size();
            for(int j = m - 1; j >= 0; --j) {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        
        vector<int>ans;
        int diagonal = 0;
        while(mp.find(diagonal) != mp.end()) {
            for(int ele : mp[diagonal]) {
                ans.push_back(ele);
            }
            diagonal++;
        }
        
        
        return ans;
    }
};