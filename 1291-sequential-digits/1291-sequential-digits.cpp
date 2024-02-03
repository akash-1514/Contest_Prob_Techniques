class Solution {
public:
    void makeSequential(int low, int high, int digit, vector<int>&ans) {
        int currDigit = digit;
        int num = 0;
        while(currDigit <= 9 && num * 10 + currDigit <= high) {
            num = num * 10 + currDigit;
            if(num >= low && num <= high) {
                ans.push_back(num);
            }
            currDigit++;
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int i = 1; i <= 9; ++i) {
            makeSequential(low, high, i, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};