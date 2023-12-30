class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size(), tot = 0;
        vector<int> vec;
        for(int i = 0; i < n; ++i) {
            vec.push_back(reward1[i] - reward2[i]);
            tot += reward2[i];
        }
        sort(vec.begin(), vec.end(), greater<int>());
        for(int i = 0; i < k; ++i) {
            tot += vec[i];
        }
        return tot;
    }
};