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
    void helper(TreeNode* root, int &ans, int mx, int mn) {
        if(!root) return;
        
        int newMx = max(mx, root->val), newMn = min(mn, root->val);
        
        helper(root->left, ans, newMx, newMn);
        helper(root->right, ans, newMx, newMn);
        
        if(mn != INT_MAX) ans = max(ans, abs(root->val - mn));
        if(mx != INT_MIN) ans = max(ans, abs(root->val - mx));
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        helper(root, ans, INT_MIN, INT_MAX);
        return ans;
    }
};