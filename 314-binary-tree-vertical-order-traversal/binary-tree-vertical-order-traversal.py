# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        q = deque()
        q.append((root,0))
        col_table = defaultdict(list)  
        while q:
            node,col = q.popleft()
            col_table[col].append(node.val)
            if node.left is not None:
                q.append((node.left,col-1))
            if node.right is not None:
                q.append((node.right,col+1))
        return [col_table[k] for k in sorted(col_table)]