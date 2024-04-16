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
        if(root == NULL) {
            if(depth == 1) {
                TreeNode* newNode = new TreeNode(val);
                return newNode;
            }
            return NULL;
        }
        
        TreeNode* newNode = NULL;
        if(depth == 1) {
            newNode = new TreeNode(val);
            if(left) {
                newNode->left = root;
            } else {
                newNode->right = root;
            }
        }
        
        root->left = dfs(root->left, val, depth - 1, true);
        root->right = dfs(root->right, val, depth - 1, false);
        
        if(depth == 1) return newNode;
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* res = dfs(root, val, depth, true);
        return res;
    }
};