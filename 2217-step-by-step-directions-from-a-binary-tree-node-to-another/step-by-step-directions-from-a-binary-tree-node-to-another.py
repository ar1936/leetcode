# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        def findLCA(node, p, q):
            if not node or node.val == p or node.val == q:
                return node
            left = findLCA(node.left, p, q)
            right = findLCA(node.right, p, q)
            if left and right:
                return node
            return left if left else right
        
        def path_lca_node(node,path,val):
            if node is None:
                return False
            if val == node.val:
                return True
            path.append('L')
            if path_lca_node(node.left,path,val):
                return True
            path.pop()
            path.append('R')
            if path_lca_node(node.right,path,val):
                return True
            path.pop()
            return False
            
        lca = findLCA(root,startValue,destValue)
        start_path = []
        dest_path = []
        path_lca_node(lca,start_path,startValue)
        path_lca_node(lca,dest_path,destValue)
        return 'U'*len(start_path) + ''.join(dest_path)