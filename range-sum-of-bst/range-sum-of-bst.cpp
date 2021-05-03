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
//     int rangeSumBST(TreeNode* root, int low, int high) {
// //         if(root==NULL)
// //             return 0;
// //         int sum=0;
        
// //           rangeSumBST(root->left,low,high);
// //          if((root->val>=low)&&(root->val<=high))
// //             sum+=root->val;
// //         rangeSumBST(root->right,low,high);
        
// //         return sum;
        
//     }
    
    
    int sum=0;
    int inorder(TreeNode* root,int L,int R)
    {
        if(root){
            inorder(root->left,L,R);
            if(root->val>=L && root->val<=R)
                sum+=root->val;
            inorder(root->right,L,R);
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)return 0;
        return inorder(root,L,R);
    }
};