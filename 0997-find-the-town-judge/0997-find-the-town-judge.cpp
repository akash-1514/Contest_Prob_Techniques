class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trustArr(n + 1);
        for(auto &t : trust) {
            trustArr[t[1]]++;
            trustArr[t[0]]--;
        }
        
        for(int i = 1; i <= n; ++i) {
            if(trustArr[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};