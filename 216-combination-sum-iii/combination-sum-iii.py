class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        nums = [i+1 for i in range(9)]
        ans = []
        def solve(ind, sum, tmp):
            if len(tmp) == k and sum == n:
                ans.append(list(tmp))
                return 
            if sum>n or ind>=len(nums):
                return 
            tmp.append(nums[ind])
            solve(ind+1, sum+nums[ind], tmp)
            tmp.pop()
            solve(ind+1, sum, tmp)
            
        
        solve(0,0,[])
        return ans