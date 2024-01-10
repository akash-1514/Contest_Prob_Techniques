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
public:
    void traverse(TreeNode* root, vector<int>&leafs) {
        if(!root) return;
        if(!root->left and !root->right) {
            leafs.push_back(root->val);
            return;
        }
        traverse(root->left, leafs);
        traverse(root->right, leafs);
    }
    bool dfs(TreeNode* root, vector<int>&leafs, int &idx) {
        if(!root) return true;
        if(!root->left and !root->right) {
            if(idx >= leafs.size() || leafs[idx++] != root->val) {
                return false;
            } 
            return true;
        }
        
        return dfs(root->left, leafs, idx) && dfs(root->right, leafs, idx);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs;
        traverse(root1, leafs);
        int idx = 0;
        return dfs(root2, leafs, idx) && idx >= leafs.size();
    }
};