class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        graph = [[10**9]*n for _ in range(n)]

        for e1, e2, w in edges:
            graph[e1][e2] = w
            graph[e2][e1] = w
            graph[e1][e1] = 0 
            graph[e2][e2] = 0 
            
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    graph[i][j] = min(graph[i][j], graph[k][j]+graph[i][k])
        
        eligible_number = 10**9
        ans_city = 0
        for i in range(n):
            sum = 0
            for j in range(n):
                if graph[i][j]<=distanceThreshold:
                    sum += 1
            if eligible_number >= sum : 
                ans_city = i
                eligible_number = sum
        return ans_city