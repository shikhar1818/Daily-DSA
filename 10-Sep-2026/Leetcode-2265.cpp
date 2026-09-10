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
    pair<int,int> fun(TreeNode* root, int& cnt){
        if(!root)
        return {0,0};

        pair<int,int> a = fun(root->left,cnt);
        pair<int,int> b = fun(root->right,cnt);

        int s = a.first + b.first+ root->val;
        int n = a.second + b.second + 1;
        if((s/n) == root->val)
        cnt++;

        pair<int,int> ans = {s,n};
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        pair<int,int> ans = fun(root,cnt);
        return cnt;
    }
};