class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        weight = [0]*n
        for (r1,r2) in roads:
            weight[r1]+=1
            weight[r2]+=1
        ans = 0
        weight = sorted(weight)
        for i in range(len(weight)):
            ans+=(weight[i]*(i+1))
        return ans