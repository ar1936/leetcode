/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int>v;
    void solve(TreeNode *root){
        if(root==NULL)
            return ;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        solve(root);
        int i=0;
        for(;i<v.size();i++){
            if(p->val==v[i])
                break;
        }
        if(i==v.size()-1)
            return NULL;
        TreeNode * temp= new TreeNode(v[i+1]);
        return temp;
    }
};