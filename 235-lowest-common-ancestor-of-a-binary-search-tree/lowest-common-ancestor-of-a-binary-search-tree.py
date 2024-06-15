# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        curr = root
        while curr:
            val = curr.val
            if p.val>val and q.val>val:
                curr = curr.right
            elif p.val<val and q.val<val:
                curr = curr.left
            else:
                return curr