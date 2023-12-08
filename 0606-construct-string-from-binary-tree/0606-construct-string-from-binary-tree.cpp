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
    string preorder(TreeNode* root, bool start) {
        if(root == NULL) {
            return "";
        }
        
        string res = "";
        if(!start) res = "(";
        res += to_string(root->val);
        
        string left = preorder(root->left, false);
        string right = preorder(root->right, false);
        
        if((left == "" && right != "") || (left != "" && right != "")) {
            if(left == "") left = "()";
            res += (left + right);
        } else if(left != "") {
            res += left;
        }
        
        if(!start) res += ")";
        return res;
    }
    string tree2str(TreeNode* root) {
        return preorder(root, true);
    }
};