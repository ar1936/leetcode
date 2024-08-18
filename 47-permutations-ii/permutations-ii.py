class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        ans = []
        def solve(ind):
            if ind== len(nums):
                ans.append(list(nums))
                return 
            used = set()
            for i in range(ind, len(nums)):
                if nums[i] in used:
                    continue
                used.add(nums[i])
                nums[i], nums[ind] = nums[ind], nums[i]
                solve(ind+1)
                nums[i], nums[ind] = nums[ind], nums[i]
                
        solve(0)
        return ans