class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = mx = mn = nums[0]
        for i in range(1,len(nums)):
            if nums[i]<0:
                mn,mx = mx,mn
            mn = min(mn*nums[i],nums[i])
            mx = max(mx*nums[i],nums[i])
            ans = max(ans,mx)
        return ans