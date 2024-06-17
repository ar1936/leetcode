class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        adj = defaultdict(list)
        inorder = defaultdict(int)
        for e in edges:
            adj[e[0]].append(e[1])
            adj[e[1]].append(e[0])
            inorder[e[1]]+=1
            inorder[e[0]]+=1
        q = deque([k for k in inorder if inorder[k]==1])
        while q:
            ans = []
            sz = len(q)
            for _ in range(sz):
                node = q.popleft()
                ans.append(node)
                for child in adj[node]:
                    inorder[child] -= 1
                    if inorder[child] ==1:
                        q.append(child)
                        
        return ans