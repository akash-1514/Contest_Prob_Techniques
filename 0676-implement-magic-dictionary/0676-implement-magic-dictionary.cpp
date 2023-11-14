class MagicDictionary {
public:
    unordered_set<string>mp;
    MagicDictionary() {
                
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &w : dictionary) {
            mp.insert(w);
        }
    }
    
    bool search(string searchWord) {
        for(int i = 0; i < searchWord.size(); ++i) {
            char ch = searchWord[i];
            for(int j = 0; j < 26; ++j) {
                if(ch == j + 'a') continue;
                searchWord[i] = j + 'a';
                if(mp.count(searchWord) == 1) {
                    return true;
                }
            }
            searchWord[i] = ch;
        }
        return false;
    }
};