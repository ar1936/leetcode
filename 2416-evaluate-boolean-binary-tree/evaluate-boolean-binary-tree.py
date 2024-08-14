class Solution:
    def solve(self,node):
        if node is None:
            return True
        if node.left is None and node.right is None:
            return node.val
        left = self.solve(node.left)
        right = self.solve(node.right)
        if node.val == 2:
            return left or right
        if node.val == 3:
            return left and right

    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        return self.solve(root)