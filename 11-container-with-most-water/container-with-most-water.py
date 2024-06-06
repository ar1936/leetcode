class Solution:
    def maxArea(self, nums: List[int]) -> int:
        ans = 0 
        n = len(nums)
        i = 0
        j = n-1
        while(i<n and j>=0):
            ans = max(ans,(j-i)*min(nums[i],nums[j]))
            if nums[i]<nums[j]:
                i+=1
            else:
                j-=1
        
        ans = max(ans,(j-i)*min(nums[i],nums[j]))
        # nums = nums[::-1]
        # i = 0
        # j = n-1
        # while(i<n and j>=0):
        #     ans = max(ans,(j-i)*min(nums[i],nums[j]))
        #     if nums[i]<nums[j]:
        #         i+=1
        #     else:
        #         j-=1
        # ans = max(ans,(j-i)*min(nums[i],nums[j]))
        return ans