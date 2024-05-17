class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = nums[0]
        mx = ans
        mn = ans
        for i in range(1,len(nums)):
            if nums[i]<0:
                mx,mn = mn,mx
            mx = max(nums[i], mx*nums[i])
            mn = min(nums[i], mn*nums[i])
            ans = max(ans,mx)
        return ans 