class Solution {
public:
    vector<pair<string, int>>vec = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
    
    string intToRoman(int num) {
        string ans = "";
        int i = 0;
        while(i < vec.size()) {
            int val = vec[i].second;
            if((num / val) != 0) {
                for(int j = 1; j <= (num / val); ++j) {
                    ans += vec[i].first;
                }
            }
            i++;
            num = num % val;
        }
        return ans;
    }
};