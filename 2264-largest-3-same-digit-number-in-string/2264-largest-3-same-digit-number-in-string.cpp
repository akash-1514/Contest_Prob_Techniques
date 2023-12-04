class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        for(int i = 0; i < n - 2; ++i) {
            string res = "";
            for(int j = i; j < i + 3; ++j) {
                res += num[j];
            }
            if(res[0] == res[1] && res[1] == res[2]) {
                ans = max(ans, res);
            }
        }
        return ans;
    }
};