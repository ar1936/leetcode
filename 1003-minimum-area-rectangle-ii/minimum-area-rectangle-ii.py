
class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        point_set = set(f"{p[0]} {p[1]}" for p in points)
        result = float('inf')
        
        def dist(p1, p2):
            return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
        
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                p1, p2 = points[i], points[j]
                
                for k in range(len(points)):
                    if dist(p1, points[k]) + dist(p2, points[k]) != dist(p1, p2):
                        continue
                    x = p1[0] + p2[0] - points[k][0]
                    y = p1[1] + p2[1] - points[k][1]
                    
                    if f"{x} {y}" not in point_set:
                        continue
                    
                    area = math.sqrt(dist(p1, points[k])) * math.sqrt(dist(p2, points[k]))
                    
                    if area == 0:
                        continue
                    
                    result = min(result, area)
        
        return 0 if result == float('inf') else result