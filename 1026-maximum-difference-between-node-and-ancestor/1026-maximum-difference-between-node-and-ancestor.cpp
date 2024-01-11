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
    pair<int, pair<int, int>> helper(TreeNode* root) {
        if(root == NULL) {
            return {INT_MIN, {INT_MAX, INT_MIN}};
        }
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        int leftRes = left.first, leftMn = left.second.first, leftMx = left.second.second;
        int rightRes = right.first, rightMx = right.second.second, rightMn = right.second.first;
        
        pair<int, pair<int, int>> ans;
        
        int mx = max(leftRes, rightRes);
        if(leftMn != INT_MAX) {
            mx = max(mx, abs(root->val - leftMn));
        } 
        
        if(leftMx != INT_MIN) {
            mx = max(mx, abs(root->val - leftMx));
        }
        
        if(rightMn != INT_MAX) {
            mx = max(mx, abs(root->val - rightMn));
        } 
        
        if(rightMx != INT_MIN) {
            mx = max(mx, abs(root->val - rightMx));
        }
        return {mx, {min({leftMn, rightMn, root->val}), max({root->val, leftMx, rightMx})}};
    }
    int maxAncestorDiff(TreeNode* root) {
        auto ans = helper(root);
        return ans.first;
    }
};