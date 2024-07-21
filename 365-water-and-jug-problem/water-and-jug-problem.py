class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        total_capacity = x+y 
        d = [x,-x,y,-y]
        q = deque()
        mp = set()
        q.append(0)
        mp.add(0)
        while q:
            current_water = q.popleft()
            if current_water == target:
                return True
            for val in d:
                current_total_water = val + current_water 
                if 0<=current_total_water<=total_capacity and current_total_water not in mp :
                    q.append(current_total_water)
                    mp.add(current_total_water)
        return False