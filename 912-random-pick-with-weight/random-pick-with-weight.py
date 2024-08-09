class Solution:

    def __init__(self, w: List[int]):
        self.pre_sum = []
        for i in range(len(w)):
            if i == 0:
                self.pre_sum.append(w[i])
            else:
                self.pre_sum.append(w[i]+self.pre_sum[-1])
             
    def pickIndex(self) -> int:
        ind = random.random() * self.pre_sum[-1]
        # ans = 0
        for i in range(len(self.pre_sum)):
            if self.pre_sum[i]>ind:
                return i
        return -1

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()