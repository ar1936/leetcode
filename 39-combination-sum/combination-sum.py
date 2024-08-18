class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        tmp = []
        def solve(ind, sum):
            if sum == target:
                ans.append(list(tmp))
                return 
            if sum>target or ind>=len(nums):
                return 
            tmp.append(nums[ind])
            solve(ind,sum+nums[ind])
            tmp.pop()
            solve(ind+1,sum)
        solve(0,0)
        return ans