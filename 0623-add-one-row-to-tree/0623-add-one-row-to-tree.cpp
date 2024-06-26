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
    TreeNode* dfs(TreeNode* root, int val, int depth, bool left) {
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            if(left) {
                newNode->left = root; 
            } else {
                newNode->right = root;
            }
            
            return newNode;
        }
        if(root == NULL) return NULL;
        
        root->left = dfs(root->left, val, depth - 1, true);
        root->right = dfs(root->right, val, depth - 1, false);
        
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* res = dfs(root, val, depth, true);
        return res;
    }
};