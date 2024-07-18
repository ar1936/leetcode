# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        arr = []
        def height(node):
            if node is None:
                return  0
            left = height(node.left)
            right = height(node.right)
            arr.append((max(left,right), node.val))
            return max(left,right) + 1 

        h = height(root)
        ans = [[] for _ in range(h)]
        for a,b in arr:
            ans[a].append(b)
        return ans