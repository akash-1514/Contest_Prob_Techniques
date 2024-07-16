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
    TreeNode* findLCA(TreeNode* root, int sv, int ev) {
        if(root == NULL) return NULL;
        if(root->val == sv || root->val == ev) return root;
        
        TreeNode* left = findLCA(root->left, sv, ev);
        TreeNode* right = findLCA(root->right, sv, ev);
        
        if(left == NULL && right == NULL) return NULL;
        else if(left == NULL) return right;
        else if(right == NULL) return left;
        return root;
    }
    
    void dfs(TreeNode* root, int sv, int ev, int depth, int &d, string &path, string &destPath) {
        if(root == NULL) return;
        if(root->val == ev) {
            destPath = path;
        }
        
        if(root->val == sv) {
            d = depth;
        }
        
        path += 'L';
        dfs(root->left, sv, ev, depth + 1, d, path, destPath);
        path.pop_back();
        
        path.push_back('R');
        dfs(root->right, sv, ev, depth + 1, d, path, destPath);
        path.pop_back();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        
        string destPath = "", path = "";
        int d = 0;
        dfs(lca, startValue, destValue, 0, d, path, destPath);
        
        string srcPath = "";
        for(int i = 0; i < d; ++i) {
            srcPath += 'U';
        }
        
        return srcPath + destPath;
    }
};