class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        def solve(ind,tmp):
            if ind == n:
                ans.append(tmp.copy())
                return 
            tmp.append(nums[ind])
            solve(ind+1,tmp)
            tmp.pop()
            solve(ind+1,tmp)
        solve(0,[])
        return ans