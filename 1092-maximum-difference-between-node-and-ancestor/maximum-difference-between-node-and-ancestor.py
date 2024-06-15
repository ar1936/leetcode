# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def solve(root,tmp,ans):
            if root is None:
                return 
            tmp.append(root.val)
            if root.left is None and root.right is None:
                ans[0] = max(max(tmp)-min(tmp),ans[0])
            solve(root.left,tmp,ans)
            solve(root.right,tmp,ans)
            tmp.pop()
        ans = [0]
        solve(root,[],ans)
        return ans[0]