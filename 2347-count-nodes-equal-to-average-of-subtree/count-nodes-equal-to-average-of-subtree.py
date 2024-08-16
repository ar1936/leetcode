# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        ans = 0
        def solve(node):
            nonlocal ans
            if node is None:
                return [0,0]
            if node.left is None and node.right is None:
                ans+=1
                return [node.val, 1]
            left = solve(node.left)
            right = solve(node.right)
            sum = left[0] + right[0] + node.val
            size = left[1] + right[1] + 1
            if sum//size == node.val:
                ans+=1
            return [sum, size]
        solve(root)
        return ans 