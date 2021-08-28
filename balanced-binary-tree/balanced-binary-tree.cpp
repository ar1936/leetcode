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
    int height(TreeNode *node){
        if(node==NULL)
            return 0;
        return max(height(node->left),height(node->right))+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        return abs(height(root->left)-height(root->right))<2 and isBalanced(root->left) and isBalanced(root->right); 
    }
};