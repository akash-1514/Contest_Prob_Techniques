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
    pair<int, int> postOrder(TreeNode* root, int &ans) {
        if(root == NULL) {
            return {0, 0};
        }
        
        auto left = postOrder(root->left, ans);
        auto right = postOrder(root->right, ans);
        
        int totSum = left.first + right.first + root->val;
        int totNodes = left.second + right.second + 1;
        
        int avg = totSum / totNodes;
        
        if(avg == root->val) {
            ans++;
        }
    
        return {totSum, totNodes};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        postOrder(root, ans);
        return ans;
    }
};