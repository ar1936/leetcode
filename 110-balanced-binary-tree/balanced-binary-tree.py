# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def height(self,node):
        if node is None:
            return 0
        left = 0
        right = 0
        left = self.height(node.left)
        right = self.height(node.right)
        return max(left, right) + 1
    
    def solve(self,root):
        
        if root is None:
            return True
        left_check = True
        right_check = True
        left_check = self.solve(root.left)
        right_check = self.solve(root.right)
        
        left_height = self.height(root.left)
        right_height = self.height(root.right)
        if abs(left_height - right_height)>1:
            return False
        return left_check and right_check 
        
    def isBalanced(self, root: Optional[TreeNode]) -> bool:            
        if root is None:
            return True
        return self.solve(root)
        