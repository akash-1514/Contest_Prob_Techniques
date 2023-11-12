class Node {
public:
    Node* links[2];
    int freq = 0;
    
    bool containsBit(int bit) {
        return links[bit] != NULL;
    }

    Node* get(int bit) {
        return links[bit];
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; --i) {
            int bit = ((num & (1 << i)) != 0);
            if(!node->containsBit(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
            node->freq++;
        }
    }
    
    void erase(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; --i) {
            int bit = (num & (1 << i)) != 0;
            node = node->get(bit);
            node->freq--;
        }
    }

    int maxXor(int num) {
        Node* node = root;
        int mx = 0;
        for(int i = 31; i >= 0; --i) {
            int bit = ((num & (1 << i)) != 0);
            if(node->containsBit(1 - bit) && node->get(1 - bit)->freq > 0) {
                mx |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return mx;
    }
};
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        Trie t;
        int i = 0, mx = 0;
        for(int j = 0; j < n;) {
            if(nums[i] * 2 >= nums[j]) {
                t.insert(nums[j]);
                j++;
            } else {
                mx = max(mx, t.maxXor(nums[i]));
                t.erase(nums[i]);
                i++;
            }
        }
        
        while(i < n) {
            mx = max(mx, t.maxXor(nums[i]));
            t.erase(nums[i]);
            i++;
        }
        
        return mx;
    }
};