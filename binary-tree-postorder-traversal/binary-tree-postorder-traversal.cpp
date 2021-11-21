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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if (root == NULL)
            return postOrder;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            // postOrder.insert(postOrder.begin(), curr->val);
            postOrder.push_back(curr->val);
            if (curr->left != NULL)
                stack.push(curr->left);
            if (curr->right != NULL)
                stack.push(curr->right);
        }
        reverse(postOrder.begin(),postOrder.end());
        return postOrder;
    }
};


// root = 1
// post = {}
// stack= 
// curr = 1 