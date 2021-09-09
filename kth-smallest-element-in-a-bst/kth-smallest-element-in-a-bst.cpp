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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        while(true){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(--k==0)
                return root->val;
            root=root->right;
        }
    }
};

// class Solution {
// public:
//     int kthSmallest(TreeNode* root , int k) {
//         stack<TreeNode*>S ;
//         int ans = 0 ; 
//         while( 1 )
//         {
//             while( root != NULL )
//             {
//                S.push(root) ;
//                root = root->left ;
//             }
//             root = S.top() ;
//             S.pop() ;
//             if( --k == 0 ) {ans = root->val ; break ; } 
//             root = root -> right ;
//         }
//         return ans ;
//     }
// // };