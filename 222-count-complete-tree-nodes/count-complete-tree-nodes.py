# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self,node):
        if node is None:
            return 0
        left = 0
        right = 0
        left = self.solve(node.left) 
        right = self.solve(node.right)
        return  left + right + 1
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0 
        return self.solve(root)