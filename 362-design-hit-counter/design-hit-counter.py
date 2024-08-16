from sortedcontainers import SortedList
class HitCounter:

    def __init__(self):
        self.st = SortedList()

    def hit(self, timestamp: int) -> None:
        self.st.add(timestamp)

    def getHits(self, timestamp: int) -> int:
        before_ind = bisect_right(self.st,timestamp-300)
        curr_ind = bisect_right(self.st,timestamp)
        return curr_ind - before_ind


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)