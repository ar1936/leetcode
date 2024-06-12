class MyCalendar:

    def __init__(self):
        self.mp = defaultdict(int)
    def book(self, start: int, end: int) -> bool:
        self.mp[start]+=1
        self.mp[end]-=1
        sum = 0
        for key in sorted(self.mp):
            sum+=self.mp[key]
            if sum>1:
                self.mp[start]-=1
                self.mp[end]+=1
                if self.mp[start]==0:
                    del self.mp[start]           
                return False
        return True

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)