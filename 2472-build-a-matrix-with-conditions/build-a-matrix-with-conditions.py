class Solution:
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        def topology_sort(nums):
            graph = defaultdict(list)
            indegree = defaultdict(int)
            ans = []
            for n1, n2 in nums:
                graph[n1].append(n2)
                indegree[n2] += 1
            q = deque()
            for key in range(1,k+1):
                if indegree[key] == 0:
                    q.append(key)
            while q:
                node = q.popleft()
                ans.append(node)
                for next_node in graph[node]:
                    indegree[next_node] -= 1
                    if indegree[next_node] == 0:
                        q.append(next_node)
            if len(ans)!=k:
                return []
            return ans
        
        row_topology = topology_sort(rowConditions)
        col_topology = topology_sort(colConditions)
        if row_topology == [] or col_topology == []:
            return []
        mat = [[0]*k for _  in range(k)]

        for i in range(k):
            for j in range(k):
                if row_topology[i] == col_topology[j]:
                    mat[i][j] = row_topology[i]
        return mat
