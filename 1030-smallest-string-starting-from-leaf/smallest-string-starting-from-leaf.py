# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        def solve(root, ans, path):
            if root is None:
                return 
            path+=chr(root.val + 97)
            if root.left is None and root.right is None:
                rev_path = path[::-1]
                if ans[0]>rev_path:
                    ans[0] = rev_path
            
            solve(root.left,ans,path)
            solve(root.right,ans,path)
            path = path[:-1]
        if root is None:
            return 
        ans = ["z"*10000]
        solve(root,ans,"")
        return ans[0]