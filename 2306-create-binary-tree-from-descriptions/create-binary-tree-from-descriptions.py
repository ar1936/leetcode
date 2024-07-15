# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        from collections import defaultdict
        
        nodes = {}
        children = set()
        
        for parent, child, is_left in descriptions:
            if parent not in nodes:
                nodes[parent] = TreeNode(parent)
            if child not in nodes:
                nodes[child] = TreeNode(child)
            
            if is_left:
                nodes[parent].left = nodes[child]
            else:
                nodes[parent].right = nodes[child]
                
            children.add(child)
        
        # The root will be a node that is not in children set
        root = None
        for parent, _, _ in descriptions:
            if parent not in children:
                root = nodes[parent]
                break
        
        return root

# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, val=0, left=None, right=None):
# #         self.val = val
# #         self.left = left
# #         self.right = right
# class Solution:
#     def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
#         mp = defaultdict(list)
#         for d in descriptions:
#             if d[0] not in mp:
#                 mp[d[0]]  = [None,None]
#             mp[d[0]][1-d[2]] = d[1] 
#         q = deque()
#         q.append(descriptions[0][0])
#         root = TreeNode(descriptions[0][0])
#         while q:
#             for _ in range(len(q)):
#                 parent_val = q.popleft()
#                 print(mp[parent_val])
#                 for [left,right] in mp[parent_val]:
#                     if left is not None:
#                         root.left = TreeNode(left)
#                         q.append(left)
#                     if right is not None:
#                         root.right = TreeNode(right)
#                         q.append(right)
#         return root       