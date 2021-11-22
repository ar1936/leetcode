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
    int  solve(int &ans, TreeNode *root){
        if(root==NULL)
            return 0;
        int l=(solve(ans,root->left));
        int r=(solve(ans,root->right));
        int temp=max(max(l,r)+root->val,root->val);
        int res=max(temp, l+r+root->val);
        ans=max(res,ans);
        return temp;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(ans,root);
        return ans;
    }
};