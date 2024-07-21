class Solution:
    def buildMatrix(self, k: int, rowConditions: List[List[int]], colConditions: List[List[int]]) -> List[List[int]]:
        def topo_sort(arr,n):
            graph = [[] for _ in range(n+1)]
            indegree = [0]*(n+1)
            for a,b in arr:
                graph[a].append(b)
                indegree[b] += 1
            q = deque()
            for k in range(1,n+1):
                if indegree[k]==0:
                    q.append(k)
            topo_sort = []
            while q:
                prev_node = q.popleft()
                topo_sort.append(prev_node)
                n-=1
                for curr_node in graph[prev_node]:
                    indegree[curr_node]-=1
                    if indegree[curr_node]==0:
                        q.append(curr_node)
            if n!=0:
                return False
            return topo_sort

        row_topo = topo_sort(rowConditions,k)
        col_topo = topo_sort(colConditions,k)
        if row_topo == False or col_topo == False:
            return []
        
        matrix = [[0] * k for _ in range(k)]
        for i in range(k):
            for j in range(k):
                if row_topo[i] == col_topo[j]:
                    matrix[i][j] = row_topo[i]
        return matrix