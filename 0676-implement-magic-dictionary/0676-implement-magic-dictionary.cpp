class MagicDictionary {
public:
    unordered_map<string, int>mp;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &w : dictionary) {
            mp[w]++;
        }
    }
    
    bool search(string searchWord) {
        int n = searchWord.size();
        for(int i = 0; i < n; ++i) {
            char ch = searchWord[i];
            for(int j = 0; j < 26; ++j) {
                if(j + 'a' == ch) continue;
                searchWord[i] = j + 'a';
                if(mp[searchWord]) return true;
            }
            searchWord[i] = ch;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */