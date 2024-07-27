# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def dfs(node, target):
            if node is None:
                return False
            if node == target:
                return True
            left = False
            right = False
            left = dfs(node.left,target)
            right = dfs(node.right,target)
            return left or right
        def lca(node,p,q):
            if node is None  or q == node or p == node:
                return node
            left = lca(node.left,p,q)
            right = lca(node.right,p,q)
            if left  and right:
                return node
            if left:
                return left
            if right:
                return right
            return None
        left = dfs(root,p)
        right = dfs(root,q)
        if left and right:
            return lca(root,p,q)
        return None