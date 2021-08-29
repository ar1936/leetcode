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
    int findBottomLeftValue1(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                level.push_back(curr->val);
            }
            ans=level[0];
        }
        return ans;
    }
    
    
    void dfs(TreeNode*root, int height, pair<int,int>&result){
        if(root->left==NULL && root->right==NULL && result.second<height)
            result={root->val,height};
        if(root->left!=NULL)
            dfs(root->left,height+1,result);
        if(root->right!=NULL)
            dfs(root->right,height+1,result);
    }
    int findBottomLeftValue(TreeNode*root){
        pair<int,int>result(root->val,1);
        dfs(root,1,result);
        return result.first;
    }
    
};