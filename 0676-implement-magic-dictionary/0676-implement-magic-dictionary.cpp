struct Node {
    Node* links[26];
    bool isEnd;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix) {
            if(!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
    
    bool searchWrongWord(string &word, int idx, bool fl, Node* root) {
        if(idx >= word.size()) {
            return fl && root->isEnd;
        }
        
        if(fl) {
            if(root->containsKey(word[idx])) {
                if(searchWrongWord(word, idx + 1, fl, root->get(word[idx]))) return true;
            } else {
                return false;
            }
        } else {
            for(int j = 0; j < 26; ++j) {
                if(root->containsKey(j + 'a')) {
                    if((j + 'a') == word[idx]) {
                        if(searchWrongWord(word, idx + 1, fl, root->get(word[idx]))) return true;
                    } else {
                        if(searchWrongWord(word, idx + 1, true, root->get(j + 'a'))) return true;   
                    }
                }
            }
        }
        return false;
    }
    
    bool searchWrongWord(string word) {
        return searchWrongWord(word, 0, false, root);
    }
};    
class MagicDictionary {
public:
    Trie t;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto &w : dictionary) {
            t.insert(w);
        }
    }
    
    bool search(string searchWord) {
        return t.searchWrongWord(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */