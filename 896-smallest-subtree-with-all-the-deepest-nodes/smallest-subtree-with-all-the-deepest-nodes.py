# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def lca(node,start,end):
            if node is None or node.val == start or node.val == end:
                return node
            left = lca(node.left,start,end)
            right = lca(node.right,start,end)
            if left and right:
                return node
            return left if left else right
        leaf = []
        q = deque()
        q.append(root)
        while q:
            level = []
            for _ in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            leaf = [level[0],level[-1]]
        return lca(root,leaf[0],leaf[1])