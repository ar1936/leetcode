# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self,p,q):
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        if p.val != q.val:
            return False
        left = True
        right = True
        left = self.solve(p.left, q.right)
        right = self.solve(p.right, q.left)
        return left and right
        
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.solve(root.left, root.right)