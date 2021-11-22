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
class BSTIterator {
    void solve(TreeNode *root, vector<int>&ans){
        if(root==NULL)
            return ;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
public:
    vector<int>ans;
    int i=0;
    BSTIterator(TreeNode* root) {
        
        solve(root,ans);
        
    }
    
    int next() {
        return ans[i++];
    }
    
    bool hasNext() {
        return i<=ans.size()-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */