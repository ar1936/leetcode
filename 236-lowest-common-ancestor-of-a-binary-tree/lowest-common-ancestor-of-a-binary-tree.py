# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # def solve(root,ans,tmp):
        #     if root is None:
        #         return 
        #     tmp.append(root.val)
        #     if root.val == p.val or root.val == q.val:
        #         ans.append(tmp.copy())
            
        #     solve(root.left,ans,tmp)
        #     solve(root.right,ans,tmp)
        #     tmp.pop()
        # ans = []
        # solve(root,ans,[])
        # prev = -1
        # for i in range(len(ans[0])):
        #     if ans[0][i] == ans[1][i]:
        #         prev = ans[0][i]
        #     else:
        #         break
        # return TreeNode(prev)
        # ans = [None]
        def solve(root,ans):
            if root is None:
                return None
            if root == p or root==q:
                ans[0] = root
                return root
            left = solve(root.left,ans)
            right = solve(root.right,ans)
            if left is not None and right is not None:
                ans[0] = root
            return left if left is not None else right

        if root is None:
            return root
        ans = [None]
        solve(root,ans)
        return ans[0]

