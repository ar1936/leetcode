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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
            return {};
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int count=q.size();
            for(int i=0;i<count;i++){
                TreeNode* curr=NULL;
                curr=q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                
            }
            ans.push_back(v);
        }
        return ans;
    }
};