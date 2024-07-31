class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # an  s =
        n = len(nums)
        for i in range(n):
            ind = abs(nums[i])
            if nums[ind-1]>0:
                nums[ind-1] *= -1
            else:
                return abs(nums[i])
        return -1