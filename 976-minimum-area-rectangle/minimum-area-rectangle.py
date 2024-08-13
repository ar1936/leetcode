class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        mp = set(tuple(point) for point in points)
        ans = 10**9
        n = len(points)
        for i in range(n):
            for j in range(i+1,n):
                x1 = points[i][0]
                x2 = points[j][0]
                y1 = points[i][1]
                y2 = points[j][1]
                if x1==x2 and y1==y2:
                    continue
                if (x1,y2) in mp and (x2,y1) in mp and abs(x2-x1)*abs(y2-y1)>0:
                    ans = min(ans,abs(x2-x1)*abs(y2-y1)) 
        return ans if ans != 10**9 else 0      