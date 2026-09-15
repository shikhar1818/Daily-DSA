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
    int deepestLeavesSum(TreeNode* root) {
       vector<vector<TreeNode*>> ans;
       ans.push_back({root});
       int k = 0;
       while(1){
        vector<TreeNode*> arr;
        for(int i = 0; i < ans[k].size(); i++){
            if(ans[k][i]->left)
            arr.push_back(ans[k][i]->left);

            if(ans[k][i]->right)
            arr.push_back(ans[k][i]->right);
        }
        int n = arr.size();
        if(n == 0)
        break;
        ans.push_back(arr);
        k++;
       }
       int n = ans.size()-1;
       int sum = 0;
       for(int i = 0; i < ans[n].size(); i++){
        sum += ans[n][i]->val;
       }
       return sum;
    }
};