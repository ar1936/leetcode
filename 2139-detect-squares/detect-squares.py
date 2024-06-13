class DetectSquares:

    def __init__(self):
        self.mp = defaultdict(int)
        self.arr = []
    def add(self, point: List[int]) -> None:
        self.arr.append(point)
        self.mp[tuple(point)] += 1
    def count(self, p: List[int]) -> int:
        ans = 0
        for (p0,p1) in self.arr:
            # this will check that side are equal 
            if abs(p0-p[0]) !=abs(p1-p[1]):
                continue
            # this will check zero area square
            if p0==p[0] or p1==p[1]:
                continue

            new_p1 = (p[0],p1)
            new_p2 = (p0,p[1])
            ans += self.mp[new_p1]*self.mp[new_p2]
        return ans

# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)