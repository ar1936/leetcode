class Solution:
    def solve(self, node, sum, targetSum):
        if node is None:
            return False
        if node.left is None and node.right is None:
            return sum+node.val == targetSum
        left = True
        right = True
        left = self.solve(node.left , sum+node.val, targetSum)
        right = self.solve(node.right, sum+node.val, targetSum)
        return left or right

    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        return self.solve(root, 0, targetSum)