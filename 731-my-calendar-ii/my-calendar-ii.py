class MyCalendarTwo:

    def __init__(self):
        self.mp = defaultdict(int)

    def book(self, start: int, end: int) -> bool:
        self.mp[start]+=1
        self.mp[end]-=1
        sum = 0
        for key in sorted(self.mp):
            sum+=self.mp[key]
            if sum>2:
                self.mp[start]-=1
                self.mp[end]+=1
                return False
        return True
