# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def lca(node,start,end):
            if node is None or node == start or node == end:
                return node
            left = lca(node.left,start,end)
            right = lca(node.right,start,end)
            if left and right:
                return node
            return left if left else right
        return lca(root,p,q)

