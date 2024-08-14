class Solution:
    def minCost(self, cost: List[List[int]]) -> int:
        n = len(cost)
        for i in range(1,n):
            for j in range(3):
                if j == 0:
                    cost[i][j] += min(cost[i-1][1], cost[i-1][2]) 
                elif j ==2:
                    cost[i][j] += min(cost[i-1][1], cost[i-1][0])
                else:
                    cost[i][j] += min(cost[i-1][0], cost[i-1][2])
        return min(cost[-1])
