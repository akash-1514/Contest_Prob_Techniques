class Solution {
public:
    bool check(string &s, int len) {
        unordered_map<char, int>mp;
        int i = 0;
        while(i < s.size()) {
            int cnt = 0;
            char ch = s[i];
            while(i < s.size() && s[i] == ch) {
                cnt++, i++;
            }
            mp[ch] += max(0, cnt - len + 1);
            if(mp[ch] >= 3) {
                return true;
            }
        }
        return false;
    }
    int maximumLength(string s) {
        int low = 1, high = s.size(), ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(check(s, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};