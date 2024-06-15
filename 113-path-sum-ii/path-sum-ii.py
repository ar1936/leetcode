# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        def solve(root,ans,tmp,sum):
            if root is None:
                return 
            sum+=root.val
            tmp.append(root.val)
            if root.left is None and root.right is None:
                if sum == targetSum:
                    ans.append(tmp.copy())
            solve(root.left,ans,tmp,sum)
            solve(root.right,ans,tmp,sum)
            sum-=root.val
            tmp.pop()
        if root is None:
            return []
        ans = []
        solve(root,ans,[],0)
        return ans
            

