class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        mp = {}
        sm = sum(nums)
        if (sm+target)%2==1:
            return 0
        find_sum = (sm+target)//2
        if find_sum<0 or sm<target:
            return 0
        def solve(ind, sum):
            if ind ==0 and sum == find_sum:
                return 1
            
            if ind < 0 or sum> find_sum:
                return 0
            if (ind,sum) in mp:
                return mp[(ind,sum)]
            mp[(ind,sum)] = solve(ind-1,sum) + solve(ind-1, sum + nums[ind-1])
            return mp[(ind,sum)] 
        return solve(len(nums),0)