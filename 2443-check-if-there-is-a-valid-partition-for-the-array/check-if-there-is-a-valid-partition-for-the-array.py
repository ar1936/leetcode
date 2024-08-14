class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        def solve(ind):
            if ind == len(nums):
                return True
            if ind > len(nums):
                return False
            if dp[ind]!=-1:
                return dp[ind]
            two_equal = False
            three_equal = False 
            three_consutive = False
            if ind+2<=len(nums):
                if nums[ind] == nums[ind+1]:
                    two_equal = solve(ind+2)
            if ind + 3 <= len(nums):
                if nums[ind] == nums[ind+1] == nums[ind+2]:
                    three_equal = solve(ind+3) 
                if nums[ind+1]-nums[ind] == 1 and nums[ind+2]-nums[ind+1] ==1:
                    three_consutive = solve(ind+3)
            dp[ind] = two_equal or three_equal or three_consutive
            return dp[ind]
        dp = [-1]*(len(nums)+1)
        return solve(0)