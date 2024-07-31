class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            ind = abs(nums[i])
            if nums[ind-1]>0:
                nums[ind-1]*=-1
        ans = []
        for i in range(n):
            if nums[i]>0:
                ans.append(i+1)
        return ans