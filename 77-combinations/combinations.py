class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        nums = [i+1 for i in range(n)]
        ans = []
        def solve(ind, tmp):
            if len(tmp) == k :
                ans.append(list(tmp))
                return 
            if ind>=len(nums):
                return
            tmp.append(nums[ind])
            solve(ind+1, tmp)
            tmp.pop()
            solve(ind+1, tmp)
        solve(0,[])
        return ans