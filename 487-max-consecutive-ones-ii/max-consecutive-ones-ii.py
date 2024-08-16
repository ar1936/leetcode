class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        left = 0
        right = 0
        ans = 0
        sum = 0
        for right in range(len(nums)):
            if nums[right] == 0:
                sum += 1
            while sum>1:
                if nums[left] == 0:
                    sum-=1
                left += 1
            ans = max(ans, right-left+1)
        return ans