# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        self.ans = []
        def solve(node,st):
            if node is None:
                return None
            node.left = solve(node.left,st)
            node.right = solve(node.right,st)
            if node.val in st:
                if node.left is not None:
                    self.ans.append(node.left)
                if node.right is  not None:
                    self.ans.append(node.right)
                return None
            return node
        st = set(to_delete)
        root = solve(root,st)
        if root is not None:
            self.ans.append(root)
        return self.ans