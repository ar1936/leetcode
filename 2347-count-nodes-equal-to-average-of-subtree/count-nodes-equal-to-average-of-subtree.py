# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        def solve(node):
            if node is None:
                return [0,0]
            if node.left is None and node.right is None:
                self.ans+=1
                return [1,node.val]
            left = solve(node.left)
            right = solve(node.right)
            size = left[0] + right[0] + 1
            sum = left[1] + right[1] + node.val
            if sum//size == node.val:
                self.ans+=1
            return [size,sum]

        self.ans = 0
        solve(root)
        return self.ans