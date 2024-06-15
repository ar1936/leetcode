# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def solve(root,ans,tmp):
            if root is None:
                return 
            tmp.append(root.val)
            if root.val == p.val or root.val == q.val:
                ans.append(tmp.copy())
            
            solve(root.left,ans,tmp)
            solve(root.right,ans,tmp)
            tmp.pop()
        ans = []
        solve(root,ans,[])
        prev = -1
        for i in range(len(ans[0])):
            if ans[0][i] == ans[1][i]:
                prev = ans[0][i]
            else:
                break
        return TreeNode(prev)