class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums = sorted(nums)
        curr = nums[0]
        ans = 0
        for i  in range(1,len(nums)):
            if nums[i] == nums[i-1]:
                curr = curr + 1
                ans += curr-nums[i]
            elif curr>=nums[i]:
                curr = curr + 1
                ans +=  curr - nums[i] 
            else:
                curr = nums[i]
        return ans

                