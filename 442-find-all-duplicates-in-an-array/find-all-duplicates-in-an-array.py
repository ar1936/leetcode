class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        for i in range(n):
            ind = abs(nums[i])
            if nums[ind-1]>0:
                nums[ind-1]*=-1
            else:
                ans.append(abs(nums[i]))
        return ans