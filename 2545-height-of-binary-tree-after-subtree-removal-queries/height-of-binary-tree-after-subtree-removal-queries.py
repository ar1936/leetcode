# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        def leftFirstPreOrder(node, height):
            nonlocal max_h
            if not node: return None
            pre[node.val] = max_h
            max_h = max(max_h, height)
            leftFirstPreOrder(node.left,height+1)
            leftFirstPreOrder(node.right,height+1)

        def rightFirstPreOrder(node, height):
            nonlocal max_h
            if not node: return None
            post[node.val] = max_h
            max_h = max(max_h, height)
            rightFirstPreOrder(node.right,height+1)
            rightFirstPreOrder(node.left,height+1)

        ans, pre, post = {}, {}, {}
        max_h = 0
        leftFirstPreOrder(root,0)
        max_h = 0
        rightFirstPreOrder(root,0)

        return [max(pre[q],post[q]) for q in queries]
            
            # if node_height + node_depth == total_height:
            #     max_depth = max(depth_dict[val] for val in depth_dict if height_dict[val] + depth_dict[val] != total_height)
            #     results.append(max(total_height - node_height - 1, max_depth))
            # else:
            #     results.append(total_height)