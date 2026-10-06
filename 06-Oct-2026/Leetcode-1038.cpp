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
    void fun(TreeNode* root,int &val){
        if(!root)
        return;
        fun(root->right,val);
        val = root->val+val;
        root->val = val;
        fun(root->left,val);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int val = 0;
        fun(root,val);
        return root;
    }
};