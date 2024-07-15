/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, unordered_map<int, int>> tree;
public:
    
    TreeNode* createTree(int root) {
        
        TreeNode* node = new TreeNode(root);
        
        if(tree.find(root) != tree.end() && tree[root].find(1) != tree[root].end()) {
            node->left = createTree(tree[root][1]);
        }
        
        if(tree.find(root) != tree.end() && tree[root].find(0) != tree[root].end()) {
            node->right = createTree(tree[root][0]);
        }
        
        return node;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    
        unordered_set<int> childs;
        // create the mapping between nodes
        for(auto d : descriptions) {
            tree[d[0]][d[2]] = d[1];
            childs.insert(d[1]);
        }
        
        int root = 0;
        for(auto d : descriptions) {
            if(!childs.count(d[0])) {
                root = d[0];
                break;
            }
        }
        
        return createTree(root);
    }
};