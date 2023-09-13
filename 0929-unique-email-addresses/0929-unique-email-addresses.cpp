class Solution {
public:
    string simplifyLocalName(string &s) {
        string res = "";
        for(char ch : s) {
            if(ch == '.') continue;
            if(ch == '+') break;
            res += ch;
        }
        return res;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int>mp;
        for(auto &email : emails) {
            string localName = "";
            int i = 0;
            while(i < email.size() && email[i] != '@') {
                localName += email[i++];
            }
            string domainName = email.substr(i + 1);
            localName = simplifyLocalName(localName);
            string uniqueEmail = localName + "," + domainName;
            mp[uniqueEmail]++;
        }
        return mp.size();
    }
};