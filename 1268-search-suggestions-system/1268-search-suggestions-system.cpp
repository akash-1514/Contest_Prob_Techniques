struct Node {
    Node* links[26];
    vector<string>suggestedWords;
    bool isEnd = false;
    
    bool containsKey(char ch) {
        return links[ch - 'a'];
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

	// TC: O(length of word)
	void insert(string word) {
		Node* node = root;
		for (char ch : word) {
			if (!node->containsKey(ch)) {
				node->put(ch, new Node());
			}
			node = node->get(ch);
            node->suggestedWords.push_back(word);
		}
		node->isEnd = true;
	}

	// O(length of word)
	bool search(string word) {
		Node* node = root;
		for (char ch : word) {
			if(!node->containsKey(ch)) {
				return false;
			}
			node = node->get(ch);
		}
		return node->isEnd;
	}

	// O(length of word)
	bool startsWith(string prefix) {
		Node* node = root;
		for (char ch : prefix) {
			if (!node->containsKey(ch)) {
				return false;
			}
			node = node->get(ch);
		}
		return true;
	}
    
    vector<vector<string>> suggestedProducts(string s) {
        int n = s.size();
        vector<vector<string>>ans(n);
        Node* node = root;
        int idx = 0;
        for(char ch : s) {
            if(!node->containsKey(ch)) {
                break;
            } else {
                node = node->get(ch);
                int cnt = 1;
                vector<string>res;
                for(auto &w : node->suggestedWords) {
                    res.push_back(w);
                    if(++cnt > 3) {
                        break;
                    }
                }
                ans[idx++] = res;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie t;
        for(auto &p : products) {
            t.insert(p);
        }
        
        vector<vector<string>>ans = t.suggestedProducts(searchWord);
        return ans;
    }
};