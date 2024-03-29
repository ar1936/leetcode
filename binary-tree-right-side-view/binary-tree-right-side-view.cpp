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
    vector<int> rightSideView1(TreeNode* root) {
        vector<vector<int>>temp;
        if(root==NULL)
            return {};
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
                if(curr->right!=NULL)
                    q.push(curr->right);
                level.push_back(curr->val);
            }
            temp.push_back(level);
        }
        vector<int>ans;
        for(auto x:temp){
            ans.push_back(x.back());
        }
        return ans;
    }
    void dfs(TreeNode *root, int height, vector<int>&ans){
        if(height==ans.size())
        {
            ans.push_back(root->val);
        }
        
        if(root->right!=NULL)
            dfs(root->right,height+1,ans);
        
        if(root->left!=NULL)
            dfs(root->left,height+1,ans);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        dfs(root,0,ans);
        return ans;
    }
};