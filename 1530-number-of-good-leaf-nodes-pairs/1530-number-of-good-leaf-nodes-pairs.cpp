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
    int ans = 0;
public:
    vector<int> mergeLeafs(vector<int>&left, vector<int>&right, int distance) {
        int i = 0, j = 0;
        vector<int> merge;
        while(i < left.size() || j < right.size()) {
            if(i < left.size() && j < right.size()) {
                if(left[i] < right[j]) {
                    merge.push_back(left[i] + 1);
                    i++;
                } else {
                    merge.push_back(right[j] + 1);
                    j++;
                }
            } else if(i < left.size()) {
                merge.push_back(left[i++] + 1);
            } else {
                merge.push_back(right[j++] + 1);
            }
        }
        
        for(int i = 0; i < left.size(); ++i) {
            for(int j = 0; j < right.size(); ++j) {
                if(left[i] + right[j] <= distance) {
                    ans++;
                }
            }
        }
       
        // for(int ele : )
        
        return merge;
    }
    vector<int> dfs(TreeNode* root, int distance) {
        if(root == NULL) {
            return {};
        }
        
        if(!root->left && !root->right) {
            return {1};
        }
        
        vector<int> left = dfs(root->left, distance);
        vector<int> right = dfs(root->right, distance);
        
        vector<int> merge = mergeLeafs(left, right, distance);
        
        return merge;
    }
    
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }
};