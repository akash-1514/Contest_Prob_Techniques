/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<int, int>vis;
    unordered_map<Node*, Node*> mp; // node copyNode
public:
    
    void dfs(Node* src, Node* srcCopiedNode) {
        vis[src->val] = 1;
        mp[src] = srcCopiedNode;
        
        for(auto &adj : src->neighbors) {
            int adjNodeVal = adj->val;
            if(!vis[adjNodeVal]) {
                Node* adjCopyNode = new Node(adjNodeVal);
                srcCopiedNode->neighbors.push_back(adjCopyNode);
                dfs(adj, adjCopyNode);
            } else {
                srcCopiedNode->neighbors.push_back(mp[adj]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* srcCopiedNode = new Node(node->val);
        dfs(node, srcCopiedNode);
        return srcCopiedNode;
    }
};