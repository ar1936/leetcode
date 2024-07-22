class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        arr = []
        def solve(ind: int, used: List[bool]) -> None:
            if ind == len(nums):
                ans.append(tuple(arr))
                return
            for i in range(len(nums)):
                if used[i] or (i > 0 and nums[i] == nums[i - 1] and not used[i - 1]):
                    continue
                used[i] = True
                arr.append(nums[i])
                solve(ind + 1, used)
                arr.pop()
                used[i] = False
                
        used = [False] * len(nums)
        solve(0, used)
        return ans
