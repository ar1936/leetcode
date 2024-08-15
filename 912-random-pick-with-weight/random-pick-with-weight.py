class Solution:

    def __init__(self, w: List[int]):
        self.pre_sum = []
        for i in range(len(w)):
            if i == 0:
                self.pre_sum.append(w[i])
            else:
                self.pre_sum.append(self.pre_sum[-1] + w[i])
            
    def pickIndex(self) -> int:
        sum = random.random()*self.pre_sum[-1]
        ind = bisect_left(self.pre_sum,sum)
        return ind
# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()