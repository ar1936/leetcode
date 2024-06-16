# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        def get_height(node):
            if node is None:
                return 0
            left_height = get_height(node.left) 
            right_height = get_height(node.right)
            return max(left_height,right_height)+1
        def update_output(node, row, left, right):
            if not node:
                return
            mid = (left + right) // 2
            self.output[row][mid] = str(node.val)
            update_output(node.left, row + 1 , left, mid - 1)
            update_output(node.right, row + 1 , mid + 1, right)
        
        height = get_height(root)-1
        print(height)
        m = height + 1
        n = 2**(height+1)-1
        self.output = [[""]*n for _ in range(m)]
        update_output(root,0,0,n)
        return self.output