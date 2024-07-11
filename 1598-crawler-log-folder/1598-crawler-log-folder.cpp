class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(auto &s : logs) {
            string sub = s.substr(0, 2);
            if(sub == "./") continue;
            if(sub == "..") {
                if(cnt > 0) cnt--;
            } else {
                cnt++;
            }
        }
        
        return cnt;
    }
};