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
    int ans=0,mx=INT_MIN;
    void solve(TreeNode *root,int mx){
        if(root==nullptr)
            return ;
        if(root->val>=mx){
            ans++;
        }
        if(root->left!=nullptr)
            solve(root->left,max(mx,root->val));
        if(root->right!=nullptr)
            solve(root->right,max(mx,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        if(root==nullptr)
            return ans++;
        solve(root,INT_MIN);
        return ans;
    }
};