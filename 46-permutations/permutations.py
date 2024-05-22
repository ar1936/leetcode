class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def solve(ind,ans):
            if ind == len(nums):
                ans.append(nums.copy())
                return 
            for i in range(ind,len(nums)):
                nums[i],nums[ind] = nums[ind], nums[i]
                solve(ind+1,ans)
                nums[i],nums[ind] = nums[ind], nums[i]
                
        ans = []
        solve(0,ans)
        return ans