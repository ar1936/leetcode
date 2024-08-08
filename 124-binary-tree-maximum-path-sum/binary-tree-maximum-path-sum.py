# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = -10**9
        def solve(node):
            if node is None:
                return 0
            nonlocal ans
            
            left = solve(node.left)
            right = solve(node.right)
            
            # Maximum path sum with the current node as the highest node
            max_left_right = max(left, right)
            max_include_curr_node = max(max_left_right + node.val, node.val)
            
            # Update the global maximum path sum
            ans = max(ans, max_include_curr_node, left + right + node.val)
            
            # Return the maximum path sum where the current node is part of the path
            return max_include_curr_node
        solve(root)
        return ans 