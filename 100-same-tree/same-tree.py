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
        if p.val!=q.val:
            return False
        left = True
        right = True
        left = self.solve(p.left, q.left)
        right = self.solve(p.right, q.right)
        return left and right 
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None and q is None:
            return True
        if p is None or q is None:
            return False
        if p.val != q.val:
            return False
        return self.solve(p,q)