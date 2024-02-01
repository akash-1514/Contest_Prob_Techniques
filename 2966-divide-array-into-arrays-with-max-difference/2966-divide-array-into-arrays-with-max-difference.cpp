class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i = 0; i < n;) {
            int curr = nums[i];
            vector<int>vec;
            int cnt = 0;
            while(i < n && nums[i] - curr <= k && cnt < 3) {
                vec.push_back(nums[i]);
                i++, cnt++;
            }
            if(cnt < 3) return {};
            ans.push_back(vec);
        }
        return ans;
    }
};