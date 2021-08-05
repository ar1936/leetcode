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
    void solve(int &sum, TreeNode *root,TreeNode*parent,TreeNode *grandparent){
        if(root==NULL)
            return ;
        if(grandparent!=NULL && grandparent-> val %2==0){
            sum+=root->val;
        }
        solve(sum,root->left,root,parent);
        solve(sum,root->right,root,parent);
    }
    
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        if(root==NULL){
            return sum;
        }
        solve(sum,root,NULL,NULL);
        return sum;
    }
};