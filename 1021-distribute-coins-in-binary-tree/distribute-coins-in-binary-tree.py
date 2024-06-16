# neetcode
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        def solve(node):
            if node is None:
                return [0,0]
            if node.left is None and node.right is None:
                return [1,node.val]
            left = solve(node.left)
            self.ans += abs(left[0]-left[1])
            right = solve(node.right)
            self.ans += abs(right[0]-right[1])
            return [left[0]+right[0]+1,left[1]+right[1]+node.val]
        solve(root)
        return self.ans