from sortedcontainers import SortedDict
class MyCalendarThree:

    def __init__(self):
        self.mp = SortedDict()

    def book(self, s: int, e: int) -> int:
        self.mp[s] = self.mp.get(s,0) + 1
        self.mp[e] = self.mp.get(e,0) - 1 
        ans = 0
        sum = 0
        for k in self.mp:
            sum += self.mp[k]
            ans = max(sum,ans)
        return ans
