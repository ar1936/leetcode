# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def solve(root,max_val,min_val,ans):
            if root is None:
                return 0
            max_val = max(max_val,root.val)
            min_val = min(min_val,root.val)
            if root.left is None and root.right is None:
                ans[0] = max(max_val-min_val,ans[0])
            left_val = solve(root.left,max_val,min_val,ans)
            right_val = solve(root.right,max_val,min_val,ans)
        ans = [0]
        solve(root,root.val,root.val,ans)
        return ans[0]