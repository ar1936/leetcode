class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        def solve(ind,tmp,sum,ans):
            if target == sum:
                ans.append(tmp.copy())
                return 
            if ind>=len(nums) or sum>target:
                return 
            tmp.append(nums[ind])
            solve(ind,tmp,sum+nums[ind],ans)
            tmp.pop()
            solve(ind+1,tmp,sum,ans)
        ans = []
        solve(0,[],0,ans)
        return ans