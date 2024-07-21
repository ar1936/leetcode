class Solution:

    def __init__(self, w: List[int]):
        self.pre_sum = []
        for i in range(len(w)):
            if i>0:
                self.pre_sum.append(self.pre_sum[i-1] + w[i])
            else:
                self.pre_sum.append(w[i])
        

    def pickIndex(self) -> int:
        target = self.pre_sum[-1] * random.random()
        return bisect_left(self.pre_sum,target)


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()