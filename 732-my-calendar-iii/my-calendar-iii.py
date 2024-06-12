class MyCalendarThree:

    def __init__(self):
        self.mp = defaultdict(int)

    def book(self, start: int, end: int) -> int:
        ans = 0
        self.mp[start] += 1
        self.mp[end] -= 1 
        sum = 0
        for key in sorted(self.mp):
            sum+=self.mp[key]
            ans = max(ans,sum)
        return ans


