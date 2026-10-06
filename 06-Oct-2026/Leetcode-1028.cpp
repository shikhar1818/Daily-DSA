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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int i = 0;
        int nums = 0;
        while(i < n && traversal[i] != '-'){
            nums = nums*10+(traversal[i]-'0');
            i++;
        }
        TreeNode* root = new TreeNode(nums);
        TreeNode* temp = root;
        unordered_map<TreeNode*,TreeNode*> mp;
        mp[root] = nullptr;
        int p = 0,c = 0;
        for(; i < n;){
            if(traversal[i] == '-'){
                c++;
                i++;
            }
            else{
                int j = i;
                int num = 0;
                while(j < n && traversal[j] != '-'){
                    num = num*10+(traversal[j]-'0');
                    j++;
                }
                TreeNode* node = new TreeNode(num);
                if(c > p){
                    temp->left = node;
                    mp[node] = temp;
                    temp = temp->left;
                }
                else{
                    int cnt = p-c+1;
                    for(int j = 0; j < cnt; j++)
                    temp = mp[temp];
                    temp->right = node;
                    mp[node] = temp;
                    temp = temp->right;
                }
                p = c;
                c = 0;
                i = j;
            }
        }
        return root;
    }
};