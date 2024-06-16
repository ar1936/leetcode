# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        def solve(node):
            if node is None:
                return [0,0]
            left_pair = solve(node.left)
            right_pair = solve(node.right)
            include = node.val + left_pair[1] + right_pair[1]
            not_include = max(left_pair) + max(right_pair)
            return [include,not_include]
        
        return max(solve(root))