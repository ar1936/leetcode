# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        def solve(node):
        
            if node is None:
                return 0 

            if node.left is None and node.right is None:
                return 1
            left = solve(node.left) if node.left else float('inf')
            right = solve(node.right) if node.right else float('inf')
            
            return min(left, right)+1
        return solve(root)


