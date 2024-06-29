class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        adj = defaultdict(list)
        inorder = defaultdict(int)
        for e1,e2 in edges:
            adj[e1].append(e2)
            inorder[e2]+=1
        q = deque()
        topo_sort = []
        for i in range(n):
            if inorder[i] == 0:
                q.append(i)
        while q:
            for _ in range(len(q)):
                node = q.popleft()
                topo_sort.append(node)
                for curr_node in adj[node]:
                    inorder[curr_node]-=1
                    if inorder[curr_node] == 0:
                        q.append(curr_node)

        ans = [[] for _ in range(n)]
        ans_set = [set() for _ in range(n)]

        for node in topo_sort:
            for neighbor in adj[node]:
                ans_set[neighbor].add(node)
                ans_set[neighbor].update(ans_set[node])
        for i in range(n):
            ans[i].extend(ans_set[i])
            ans[i].sort()
        return ans