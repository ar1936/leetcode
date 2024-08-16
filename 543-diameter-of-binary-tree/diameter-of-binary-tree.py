# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def solve(node):
            nonlocal ans
            if node is None:
                return 0 
            left = 0 
            right = 0
            left = solve(node.left)
            right = solve(node.right)
            # if this node have maxium diameeter then 
            ans = max(ans,left+right)
            return max(left,right)+1
        if root is None:
            return 0
        solve(root)
        return ans