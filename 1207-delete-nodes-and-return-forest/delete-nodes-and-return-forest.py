# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        ans = []
        to_delete = set(to_delete)
        def solve(node):
            if node is None:
                return None
            node.left = solve(node.left)
            node.right = solve(node.right)

            if node.val in to_delete:
                if node.left:
                    ans.append(node.left)
                if node.right:
                    ans.append(node.right)
                return None
            return node
        if root is None:
            return None
        root = solve(root)
        if root is not None:
            ans.append(root)
        return ans