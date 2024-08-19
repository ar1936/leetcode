class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        ans = 0 
        left = 0
        right = 0 
        prod = 1
        if k in [0,1]:
            return 0
        for right in range(len(nums)):
            prod *= nums[right]
            while left<len(nums) and  prod>=k:
                prod/=nums[left]
                left+=1
            ans += (right - left + 1)
        return ans