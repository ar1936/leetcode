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
    TreeNode *helper(int left,int right,vector<int>nums){
        if(left>right)
            return NULL;
        int p=(left+right)/2;
        TreeNode *root= new TreeNode(nums[p]);
        root->left=helper(left,p-1,nums);
        root->right=helper(p+1,right,nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0,nums.size()-1,nums);
    }
};