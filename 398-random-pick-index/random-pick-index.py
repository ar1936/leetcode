class Solution:

    def __init__(self, nums: List[int]):
        self.mp = defaultdict(list)
        for i in range(len(nums)):
            self.mp[nums[i]].append(i)

    def pick(self, target: int) -> int:
        l = len(self.mp[target])
        r = random.random() * l
        return self.mp[target][int(r)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)