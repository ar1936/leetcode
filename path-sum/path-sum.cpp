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
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int sum) {
//         if(root==NULL)
//             return false;
//         if(sum==0)
//             return true;
//         hasPathSum(root->left, sum-=root->val);
//         sum+=root->val;
//         hasPathSum(root->right, sum-=root->val);
//         sum+=root->val;
//         return false;
//     }
// };

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;                                         
        sum=sum-root->val;                                           
        if(sum==0&&!root->left&&!root->right)
            return true; 
        bool left_flag=hasPathSum(root->left,sum);
        bool right_flag=hasPathSum(root->right,sum);
        return left_flag||right_flag;
    }
};