# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def solve(node):
            nonlocal ans
            if node is None:
                return -1
            left = solve(node.left) + 1
            right = solve(node.right) + 1
            tmp = max(left, right)
            ans = max(left+right,ans)
            return tmp
        solve(root)
        return ans