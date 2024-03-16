class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> vec(102, 0);
        for(auto &ele : nums) {
            vec[ele[0]]++;
            vec[ele[1] + 1]--;
        }
        
        for(int i = 1; i <= 101; ++i) {
            vec[i] += vec[i - 1];
        }
        
        int mx = 0;
        int cnt = 0;
        for(int i = 0; i <= 101; ++i) {
            cnt += (vec[i] > 0);
        }
        
        return cnt;
    }
};