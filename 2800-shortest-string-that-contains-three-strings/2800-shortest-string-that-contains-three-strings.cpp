class Solution {
public:
    string merge(string &s1, string s2) {
        if(s1.find(s2) != string::npos) {
            return s1;
        }
        
        int idx1 = -1;
        for(int i = 0; i < s1.size(); ++i) {
            if(s1[i] == s2[0]) {
                int k = 0, j;
                for(j = i; j < s1.size() && k < s2.size(); ++j) {
                    if(s1[j] != s2[k++]) {
                        break;
                    }
                }
                if(j == s1.size()) {
                    idx1 = i;
                    break;
                }
            }
        }
        
        if(idx1 == -1) {
            return s1 + s2; 
        } else {
            int len = s1.size() - idx1;
            string res = s1.substr(0, idx1) + s1.substr(idx1) + s2.substr(len);
            return res;
        }
    }
    string minimumString(string a, string b, string c) {
        vector<string>vec = {a, b, c};
        string ans;
        int mn = 1e9;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                for(int k = 0; k < 3; ++k) {
                    if(i != j && j != k && i != k) {
                        string s1 = vec[i], s2 = vec[j], s3 = vec[k];
                        string mergeStr = merge(s1, s2);
                        string mergeStr2 = merge(mergeStr, s3);
                        if(mergeStr2.size() < mn) {
                            mn = mergeStr2.size();
                            ans = mergeStr2;
                        } else if(mn == mergeStr2.size()) {
                            ans = min(ans, mergeStr2);
                        }
                    }
                }
            }
        }
        return ans;
    }
};