from sortedcontainers import SortedDict
class RangeModule:

    def __init__(self):
        self.intervals = SortedDict()

    def addRange(self, left: int, right: int) -> None:
        to_remove = []
        for start, end in self.intervals.items():
            if end < left:
                continue
            if start > right:
                break
            to_remove.append(start)
            left = min(left, start)
            right = max(right, end)

        for start in to_remove:
            self.intervals.pop(start)

        self.intervals[left] = right

    def queryRange(self, left: int, right: int) -> bool:
        pos = self.intervals.bisect_right(left)
        if pos == 0:
            return False
        start, end = self.intervals.peekitem(pos - 1)
        return start <= left and right <= end 

    def removeRange(self, left: int, right: int) -> None:
        to_remove = []
        to_add = []
        for start, end in self.intervals.items():
            if end <= left or start >= right:
                continue
            to_remove.append(start)
            if start < left:
                to_add.append((start, left))
            if end > right:
                to_add.append((right, end))
        
        for start in to_remove:
            self.intervals.pop(start)
        
        for start, end in to_add:
            self.intervals[start] = end
                


# Your RangeModule object will be instantiated and called as such:
# obj = RangeModule()
# obj.addRange(left,right)
# param_2 = obj.queryRange(left,right)
# obj.removeRange(left,right)